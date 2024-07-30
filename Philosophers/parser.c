/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:10:58 by whamdi            #+#    #+#             */
/*   Updated: 2024/07/30 16:18:55 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"

void ft_check_param(char *input, int i, t_data *data)
{
	//number_of_philosophers time_to_die time_to_eat time_to_sleep
	//[number_of_times_each_philosopher_must_eat]
	if(i == 1)// check
		data->philo_nbr = ft_atoi(input);
	if(i == 2)
		data->time_die = ft_atoi(input);
	if(i == 3)
		data->time_eat = ft_atoi(input);
	if(i == 4)
		data->time_sleep = ft_atoi(input);
	if(i == 5)
		data->eat_cycle = ft_atoi(input);
}

int ft_parser(char **input, t_data *data)
{
	int i;
	i = 0;
	while(input[i])
	{
		ft_check_param(input[i], i,data);
		i++;
	}
	if(data->philo_nbr > 200)
	{
		printf("Number of philo can't exceed 200\n");
		exit(EXIT_FAILURE);
	}
	return(0);
}
