/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:07:50 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/01 15:16:26 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"
#include <stdio.h>

void	write_think(t_data *data, int i)
{
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d is thinking[🤔]...\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
}

bool	fork_for_all(t_data *data, int left_fork, int right_fork, int i)
{
	pthread_mutex_lock(&data->philos[right_fork].fork);
	if (check_flag(data) == true || check_flagda(data) == true)
		return (false);
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d has taken a right fork[🍴]\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
	pthread_mutex_lock(&data->philos[left_fork].fork);
	if (check_flag(data) == true || check_flagda(data) == true)
		return (false);
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d has taken a left fork[🍴]\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
	return (true);
}

bool	fork_last(t_data *data, int left_fork, int right_fork, int i)
{
	pthread_mutex_lock(&data->philos[left_fork].fork);
	if (check_flag(data) == true || check_flagda(data) == true)
		return (false);
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d has taken a left fork[🍴]\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
	pthread_mutex_lock(&data->philos[right_fork].fork);
	if (check_flag(data) == true || check_flagda(data) == true)
		return (false);
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d has taken a right fork[🍴]\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
	return (true);
}

int	isdying_box(t_data *data, int compare)
{
	if (data->eat_cycle > -1 && compare >= data->eat_cycle)
	{
		data->flagada = 1;
		return (1);
	}
	return (0);
}

int	ft_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf(" Error getting time \n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
