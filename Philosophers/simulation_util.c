/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:48:33 by whamdi            #+#    #+#             */
/*   Updated: 2024/07/31 17:50:28 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"

int	mutex_init(t_data *data)
{
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
	{
		printf("Write mutex initialization failed\n");
		return (-1);
	}
	if (pthread_mutex_init(&data->general_mutex, NULL) != 0)
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
	return (0);
}

int	init_philo_thread(t_data *data, int i)
{
	data->philos[i].id = i + 1;
	data->philos[i].data = data;
	data->philos[i].eat_counter = 0;
	if (pthread_mutex_init(&data->philos[i].fork, NULL) != 0)
	{
		printf("Mutex initialization failed for philosopher %d\n", i);
		return (-1);
	}
	return (0);
}
