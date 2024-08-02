/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:48:33 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/02 15:33:18 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"
#include <pthread.h>

void	middle_init(t_data *data)
{
	data->philos[data->i].id = 0;
	data->i = 0;
}

int	mutex_init(t_data *data)
{
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
	{
		printf("Write mutex initialization failed\n");
		return (-1);
	}
	if (pthread_mutex_init(&data->philonbr_mutex, NULL) != 0)
	{
		printf("Write mutex initialization failed\n");
		return (-1);
	}
	if (pthread_mutex_init(&data->flag_mutex, NULL) != 0)
	{
		printf("Write mutex initialization failed\n");
		return (-1);
	}
	if (pthread_mutex_init(&data->eatcounter_mutex, NULL) != 0)
	{
		printf("Write mutex initialization failed\n");
		return (-1);
	}
	if (pthread_mutex_init(&data->flagada_mutex, NULL) != 0)
	{
		printf("Write mutex initialization failed\n");
		return (-1);
	}
	if (pthread_mutex_init(&data->lastmeal_mutex, NULL) != 0)
	{
		printf("Write mutex initialization failed\n");
		return (-1);
	}	
	if (pthread_mutex_init(&data->salleat_mutex, NULL) != 0)
	{
		printf("Write mutex initialization failed\n");
		return (-1);
	}
	int i = 0;
	data->forks = malloc(data->philo_nbr * sizeof(pthread_mutex_t) + 1);
	while(i < data->philo_nbr)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->initphilo_mutex,NULL);
	return (0);
}

int	init_philo_thread(t_data *data, int i)
{
	data->philos[i].id = i + 1;
	data->philos[i].hold_right = 0;
	data->philos[i].hold_left = 0;
	data->philos[i].data = data;
	pthread_mutex_lock(&data->eatcounter_mutex);
	data->philos[i].eat_counter = 0;
	pthread_mutex_unlock(&data->eatcounter_mutex);

	// if (i == data->philo_nbr - 1)
	// {
	// 	data->philos[i].left_fork = &data->forks[i];
	// 	data->philos[i].right_fork = &data->forks[0];
	// }
	// else
	// {
	// 	data->philos[i].left_fork = &data->forks[i];
	// 	data->philos[i].right_fork = &data->forks[i + 1];
	// }
	data->philos[i].left_fork = &data->forks[i];
	data->philos[i].right_fork = &data->forks[i + 1];
	return (0);
}
