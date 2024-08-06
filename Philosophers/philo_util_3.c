/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:14:44 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/06 11:59:51 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"
#include <stdio.h>

int	isdying_box1(t_data *data, int save_all_eats, int refresh_eatcounter, int i)
{
	long	time_since_last_meal;

	(void)save_all_eats;
	(void)refresh_eatcounter;
	pthread_mutex_lock(&data->lastmeal_mutex);
	time_since_last_meal = ft_time() - data->philos[i].last_meal;
	pthread_mutex_unlock(&data->lastmeal_mutex);
	if (time_since_last_meal > data->time_die + 4)
	{
		pthread_mutex_lock(&data->flag_mutex);
		data->flag = 1;
		pthread_mutex_unlock(&data->flag_mutex);
		pthread_mutex_lock(&data->write_mutex);
		printf("%ld %d died\n", (ft_time() - data->ms), data->philos[i].id);
		pthread_mutex_unlock(&data->write_mutex);
		return (1);
	}
	return (0);
}

void	mutex_eatcounter(t_data *data)
{
	pthread_mutex_lock(&data->eatcounter_mutex);
	data->refresh_eatcounter = data->philos[data->i].eat_counter;
	pthread_mutex_unlock(&data->eatcounter_mutex);
	pthread_mutex_lock(&data->salleat_mutex);
	data->s_all_eats += 1;
	pthread_mutex_unlock(&data->salleat_mutex);
	data->i++;
}
