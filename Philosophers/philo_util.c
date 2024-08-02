/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:07:50 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/02 14:17:20 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"
#include <pthread.h>
#include <stdio.h>

void	write_think(t_data *data, int i)
{
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d is thinking[🤔]...\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
}

int	isdying_box(t_data *data, t_philo *philo)
{
	int	i;
	int	tmp_eatcounter;

	tmp_eatcounter = 0;
	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_mutex_lock(&data->eatcounter_mutex);
		tmp_eatcounter = philo[i].eat_counter;
		pthread_mutex_unlock(&data->eatcounter_mutex);
		if (data->eat_cycle == -1 || tmp_eatcounter < data->eat_cycle)
			return (0);
		i++;
	}
	pthread_mutex_lock(&data->flagada_mutex);
	data->flagada = 1;
	pthread_mutex_unlock(&data->flagada_mutex);
	return (1);
}

int	ft_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf(" Error getting time \n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
