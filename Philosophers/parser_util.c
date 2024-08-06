/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:11:07 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/06 10:18:13 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"

int	ft_atoi(const char *nbr)
{
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	while (*nbr && (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13)))
		++nbr;
	if (*nbr && (*nbr == '-' || *nbr == '+'))
	{
		if (*nbr++ == '-')
			sign = -1;
	}
	while (*nbr && (*nbr >= '0' && *nbr <= '9'))
	{
		if (result > (2147483647 - (*nbr - '0')) / 10)
		{
			if (sign == 1)
				return (2147483647);
			else
				return (-2147483647 - 1);
		}
		result = (*nbr++ - '0') + result * 10;
	}
	return ((int)(result * sign));
}
