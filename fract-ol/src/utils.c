/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:45:04 by whamdi            #+#    #+#             */
/*   Updated: 2024/04/25 11:12:08 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_lib.h"

void	split_destroy(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	atof_checker(const char *s, int flag, t_fract *data, int neg)
{
	int	i;

	i = 0;
	neg = 1;
	flag = 0;
	if (s[0] == '-' && s[1] != '0')
		ft_atof_exit(data);
	if (s[0] != '0' && s[0] != '-')
		ft_atof_exit(data);
	while (s[i])
	{
		if (s[i] == '-')
		{
			neg = -neg;
			flag -= 1;
		}
		if ((!(s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
			flag += 1;
		i++;
	}
	if (flag > 1 || flag == 0)
		ft_atof_exit(data);
	if (neg == -neg)
		return (1);
	return (0);
}

double	ft_atof(const char *s, int power, int neg, t_fract *data)
{
	char	**string;
	int		a;
	int		b;
	int		temp;
	double	result;

	power = 0;
	neg = 1;
	if (atof_checker(s, 0, data, 0) == 1)
		neg = -neg;
	string = ft_split(s, '.');
	a = ft_atoi(string[0]);
	b = ft_atoi(string[1]);
	temp = b;
	while (temp >= 1)
	{
		temp = temp / 10;
		power++;
	}
	split_destroy(string);
	return (result = a + (b / pow(10, power)) * neg);
}

int	ft_hex_to_dec(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	c = ft_toupper(c);
	if (c >= 'A' && c <= 'F')
		return (10 + c - 'A');
	return (-1);
}

void	ft_parser(t_fract *data)
{
	if (ft_strlen(data->argv[1]) > 1)
		return ;
	if (data->argc > 2)
	{
		if (data->argc < 4 && ft_tolower(data->argv[1][0]) != 'm')
		{
			ft_printf("Add a third parameter\n");
			free(data);
			exit(EXIT_FAILURE);
		}
		if (ft_tolower(data->argv[1][0]) == 'j')
		{
			data->param_1 = ft_atof(data->argv[2], 0, 1, data);
			data->param_2 = ft_atof(data->argv[3], 0, 1, data);
		}
		if (data->argc == 3 && ft_tolower(data->argv[1][0]) == 'm')
			data->hex_color = ft_extract_color(data->argv[2], data);
	}
	if (data->argc == 1)
	{
		data->param_1 = 0.0;
		data->param_2 = 0.0;
		data->hex_color = 0xFF0000;
	}
}
