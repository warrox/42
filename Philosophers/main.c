/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:10:52 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/01 20:29:09 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"
#include <stdio.h>

void	ft_issleeping(t_data *data, int i)
{
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d is sleeping[😴]\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
	ft_usleep(data->time_sleep, data);
}

void	ft_eat(t_data *data, int i)
{
	pthread_mutex_lock(&data->general_mutex);
	data->philos[i].last_meal = ft_time();
	pthread_mutex_unlock(&data->general_mutex);
	pthread_mutex_lock(&data->eatcounter_mutex);
	data->philos[i].eat_counter += 1;
	pthread_mutex_unlock(&data->eatcounter_mutex);
	pthread_mutex_lock(&data->write_mutex);
	printf("%ld %d is eating[🍝]\n", ft_time() - data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
	ft_usleep(data->time_eat, data);
}

bool	ft_takefork(t_data *data, int i)
{
	data->left_fork = i % data->philo_nbr;
	data->right_fork = (i + 1) % data->philo_nbr;
	if (check_flagda(data))
		return (false);
	if (i == data->philo_nbr - 1)
	{
		if (fork_for_all(data, data->left_fork, data->right_fork, i) == false)
			return (false);
	}
	else
	{
		if (fork_last(data, data->left_fork, data->right_fork, i) == false)
			return (false);
	}
	return (true);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = (t_philo *)arg;
	data = philo->data;
	i = philo->id;
	while (1)
	{
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
		ft_takefork(data, i);
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
		ft_eat(data, i);
		pthread_mutex_unlock(&data->philos[i % data->philo_nbr].fork);
		pthread_mutex_unlock(&data->philos[(i + 1) % data->philo_nbr].fork);
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
		ft_issleeping(data, i);
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
		write_think(data, i);
		if (check_flag(data) == true || check_flagda(data) == true)
			break ;
	}
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
