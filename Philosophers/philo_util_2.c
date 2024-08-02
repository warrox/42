/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:51:51 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/02 11:46:15 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"
#include <pthread.h>
#include <stdio.h>

bool	check_flagda(t_data *data)
{
	pthread_mutex_lock(&data->flagada_mutex);
	if (data->flagada == 1)
	{
		pthread_mutex_unlock(&data->flagada_mutex);
		return (true);
	}
	pthread_mutex_unlock(&data->flagada_mutex);
	return (false);
}

int	philo_counter(t_data *data)
{
	int	i;

	i = 0;
	while (data->philos[i].id)
		i++;
	return (i);
}

bool	check_flag(t_data *data)
{
	pthread_mutex_lock(&data->flag_mutex);
	if (data->flag == 1)
	{
		pthread_mutex_unlock(&data->flag_mutex);
		return (true);
	}
	pthread_mutex_unlock(&data->flag_mutex);
	return (false);
}

void	*ft_isdying(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	data->i = 0;
	data->s_all_eats = 0;
	data->refresh_eatcounter = 0;
	while (1)
	{
		data->i = 1;
		while (data->i < data->philo_nbr)
		{
			if (isdying_box1(data, data->s_all_eats, data->refresh_eatcounter,
					data->i) == 1)
				return (NULL);
			if (isdying_box(data, data->philos) == 1)
				return (NULL);
			data->i++;
		}
		usleep(1000);
	}
	return (NULL);
}

void	ft_usleep(int time, t_data *data)
{
	int	end_time;

	end_time = ft_time() + time;
	(void)data;
	while (ft_time() <= end_time)
	{
		usleep(1000);
	}
}
