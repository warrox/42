/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:35:46 by whamdi            #+#    #+#             */
/*   Updated: 2024/04/24 17:02:13 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_lib.h"

void	decimal_to_rgb(unsigned int decimal_color, t_fract *data)
{
	data->red = (decimal_color >> 16) & 0xFF;
	data->green = (decimal_color >> 8) & 0xFF;
	data->blue = decimal_color & 0xFF;
}

void	ft_pix_colorization(t_fract *data)
{
	data->red = (data->n % 256);
	data->green = (data->n * 2 % 256);
	data->blue = (data->n * 3 % 256);
	data->hex_color = (data->red << 16) | (data->green << 8) | data->blue;
}

void	ft_color_in_out(t_fract *data)
{
	if (data->is_inside)
	{
		data->hex_background = 0x4c00b0;
		render(data);
	}
	else
	{
		if (data->argc == 3)
		{
			decimal_to_rgb(data->hex_color, data);
			render(data);
			return ;
		}
		ft_pix_colorization(data);
		render(data);
	}
}

void	ft_error_hexa_message(t_fract *data)
{
	ft_printf("\033[31m You must enter a correct hexadecimal number\033[0m\n");
	free(data);
	exit(EXIT_FAILURE);
}

int	ft_extract_color(char *hex, t_fract *data)
{
	int	result;
	int	i;
	int	len;
	int	dec;

	i = 0;
	dec = 0;
	result = 0;
	len = ft_strlen(hex);
	while (i < len)
	{
		if ((hex[i] >= '0' && hex[i] <= '9') || (ft_tolower(hex[i]) >= 'a'
				&& ft_tolower(hex[i]) <= 'f'))
		{
			dec = ft_hex_to_dec(hex[i]);
			if (dec >= 0)
				result += dec * pow(16, len - 1 - i);
			i++;
		}
		else
			ft_error_hexa_message(data);
	}
	return (result);
}
