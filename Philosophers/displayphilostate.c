/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayphilostate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:49:25 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/01 11:23:21 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"

void	display_state(t_data *data)
{
	printf("--------------------\n");
	printf("%d has taken a fork\n", data->philo_nbr);
	printf("%d is eating\n", data->philo_nbr);
	printf("%d is sleeping\n", data->philo_nbr);
	printf("%d is thinking\n", data->philo_nbr);
	printf("%d died\n", data->philo_nbr);
}

void	display_all_data(t_data *data)
{
	int	i;

	i = 0;
	printf("--------------------\n");
	printf("%d has taken a fork\n", data->philo_nbr);
	printf("%d is eating\n", data->philo_nbr);
	printf("%d is sleeping\n", data->philo_nbr);
	printf("%d is thinking\n", data->philo_nbr);
	printf("%d died\n", data->philo_nbr);
	printf("--------------------\n");
}
