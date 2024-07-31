/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:10:58 by whamdi            #+#    #+#             */
/*   Updated: 2024/07/31 16:10:56 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

void ft_check_param(char *input, int i, t_data *data)
{
	
	if(i == 1)
		data->philo_nbr = ft_atoi(input);
	if(i == 2)
		data->time_die = ft_atoi(input);
	if(i == 3)
		data->time_eat = ft_atoi(input);
	if(i == 4)
		data->time_sleep = ft_atoi(input);
	if(i == 5)
		data->eat_cycle = ft_atoi(input);
	else
		data->eat_cycle = -1;
}

int ft_parser(char **input, t_data *data)
{
	int i;
	int j;
	i = 1;
	j = 0;
	
	while(input[i])
	{
		j= 0;
		while(input[i][j])
		{
			if(ft_isalpha(input[i][j]))
			{
				printf("Use only digit number\n");
				return(-1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while(input[i])
	{
		ft_check_param(input[i], i,data);
		i++;
	}
	if(data->philo_nbr > 200)
	{
		printf("Number of philo can't exceed 200\n");
		return(-1);
	}
	return(0);
}
