/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:14:44 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/01 14:16:19 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"

int	isdying_box1(t_data *data, int save_all_eats, int refresh_eatcounter, int i)
{
	long	time_since_last_meal;

	(void)save_all_eats;
	(void)refresh_eatcounter;
	pthread_mutex_lock(&data->general_mutex);
	time_since_last_meal = ft_time() - data->philos[i].last_meal;
	pthread_mutex_unlock(&data->general_mutex);
	if (time_since_last_meal > data->time_die && data->philos[i].id != 0)
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
	pthread_mutex_lock(&data->general_mutex);
	data->s_all_eats += 1;
	pthread_mutex_unlock(&data->general_mutex);
	data->i++;
}
