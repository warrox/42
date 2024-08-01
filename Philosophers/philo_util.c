/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:07:50 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/01 11:23:48 by whamdi           ###   ########.fr       */
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

int	isdying_box(t_data *data, int save_all_eats, int refresh_eatcounter, int i)
{
	long	time_since_last_meal;

	if (refresh_eatcounter >= data->eat_cycle && data->eat_cycle > 0)
	{
		if (save_all_eats >= data->philo_nbr)
		{
			data->flagada = 1;
			return (1);
		}
	}
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

int	ft_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf(" Error getting time \n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
