/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:10:52 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/06 12:16:38 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"
#include <pthread.h>
#include <stdio.h>

void	ft_eat(t_data *data, int i)
{
	pthread_mutex_lock(&data->lastmeal_mutex);
	data->philos[i].last_meal = ft_time();
	pthread_mutex_unlock(&data->lastmeal_mutex);
	pthread_mutex_lock(&data->eatcounter_mutex);
	data->philos[i].eat_counter += 1;
	pthread_mutex_unlock(&data->eatcounter_mutex);
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d is eating\n", ft_time() - data->ms, data->philos[i].id);
	pthread_mutex_unlock(&data->write_mutex);
	ft_usleep(data->time_eat, data);
	pthread_mutex_lock(&data->philonbr_mutex);
	data->philos[i].hold_right = 0;
	data->philos[i].hold_left = 0;
	if (i == data->philo_nbr - 1)
	{
		pthread_mutex_unlock(&data->philonbr_mutex);
		pthread_mutex_unlock(data->philos[i].right_fork);
		pthread_mutex_unlock(data->philos[i].left_fork);
	}
	else
	{
		pthread_mutex_unlock(&data->philonbr_mutex);
		pthread_mutex_unlock(data->philos[i].left_fork);
		pthread_mutex_unlock(data->philos[i].right_fork);
	}
}

bool	ft_takefork(t_data *data, int i)
{
	pthread_mutex_lock(data->philos[i].left_fork);
	data->philos[i].hold_left = 1;
	if (check_flag(data) == true || check_flagda(data) == true)
	{
		return (false);
	}
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d has taken a fork\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
	pthread_mutex_lock(data->philos[i].right_fork);
	data->philos[i].hold_right = 1;
	if (check_flag(data) == true || check_flagda(data) == true)
	{
		return (false);
	}
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d has taken a fork\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
	return (true);
}

void	while_routine(t_data *data, int i)
{
	while (1)
	{
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
		if (ft_takefork(data, i) == false)
			break ;
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
		ft_eat(data, i);
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
		ft_issleeping(data, i);
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
		write_think(data, i);
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
	}
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = (t_philo *)arg;
	data = philo->data;
	i = philo->id - 1;
	while_routine(data, i);
	if (data->philos[i].hold_left == 1)
		pthread_mutex_unlock(data->philos[i].left_fork);
	if (data->philos[i].hold_right == 1)
		pthread_mutex_unlock(data->philos[i].right_fork);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.flag = 0;
	data.flagada = 0;
	if (argc < 5)
	{
		printf("Not enough parameters.\n");
		printf("Exiting Philo\n");
		exit(EXIT_FAILURE);
	}
	if (ft_parser(argv, &data) == -1)
		return (-1);
	data.ms = ft_time();
	if (data.philo_nbr == 1)
	{
		printf("%ld %d has taken a fork[🍴]\n", ft_time() - data.ms, 1);
		usleep(data.time_die * 1000);
		printf("%ld %d died\n", (ft_time() - data.ms), 1);
		return (0);
	}
	start_simulation(&data);
	return (0);
}
