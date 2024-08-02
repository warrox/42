/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:10:13 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/02 16:01:18 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"

int	create_philo(t_data *data, int i)
{
	pthread_mutex_lock(&data->lastmeal_mutex);
	data->philos[i].last_meal = ft_time();
	pthread_mutex_unlock(&data->lastmeal_mutex);
	if (pthread_create(&data->philos[i].thread, NULL, ft_routine,
			(void *)&data->philos[i]) != 0)
	{
		printf("Error creating thread %d\n", i);
		return (-1);
	}
	return (0);
}

int	dying_watcher(t_data *data)
{
	if (pthread_create(&data->die_thread, NULL, ft_isdying, (void *)data) != 0)
	{
		printf("Error creating death monitoring thread\n");
		return (-1);
	}
	return (0);
}

int	join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
		{
			printf("Error joining thread %d\n", i);
			return (-1);
		}
		i++;
	}
	pthread_join(data->die_thread, NULL);
	return (0);
}

void	destroy_and_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->eatcounter_mutex);
	pthread_mutex_destroy(&data->philonbr_mutex);
	pthread_mutex_destroy(&data->flag_mutex);	
	pthread_mutex_destroy(&data->flagada_mutex);
	pthread_mutex_destroy(&data->eatcounter_mutex);
	pthread_mutex_destroy(&data->lastmeal_mutex);
	pthread_mutex_destroy(&data->salleat_mutex);
	free(data->philos);
	free(data->forks);
}

int	start_simulation(t_data *data)
{
	int cpy_philonbr;

	data->i = 0;	
	// pthread_mutex_lock(&data->philonbr_mutex);
	cpy_philonbr = data->philo_nbr;
	// pthread_mutex_unlock(&data->philonbr_mutex);	
	// pthread_mutex_lock(&data->initphilo_mutex);
	data->philos = malloc(sizeof(t_philo) * (cpy_philonbr + 1));
	// pthread_mutex_unlock(&data->initphilo_mutex);
	if (!data->philos)
		return (-1);
	if (mutex_init(data) == -1)
		return (-1);
	while (data->i < data->philo_nbr)
	{
		if (init_philo_thread(data, data->i) == -1)
			return (-1);
		data->i++;
	}
	middle_init(data);
	while (data->i < data->philo_nbr)
	{
		if (create_philo(data, data->i) == -1)
			return (-1);
		usleep(500);
		data->i++;
	}
	data->i = 0;
	dying_watcher(data);
	if (join_thread(data) == -1)
		return (-1);
	destroy_and_free(data);
	return (0);
}
