/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:10:13 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/01 11:48:16 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"

int	create_philo(t_data *data, int i)
{
	pthread_mutex_lock(&data->general_mutex);
	data->philos[i].last_meal = ft_time();
	pthread_mutex_unlock(&data->general_mutex);
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
		pthread_mutex_destroy(&data->philos[i].fork);
		i++;
	}
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->eatcounter_mutex);
	pthread_mutex_destroy(&data->general_mutex);
	pthread_mutex_destroy(&data->flag_mutex);
	free(data->philos);
}

int	start_simulation(t_data *data)
{
	data->i = 0;
	data->philos = malloc(sizeof(t_philo) * (data->philo_nbr + 1));
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
		usleep(50);
		data->i++;
	}
	dying_watcher(data);
	if (join_thread(data) == -1)
		return (-1);
	destroy_and_free(data);
	return (0);
}
