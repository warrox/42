/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:50:35 by whamdi            #+#    #+#             */
/*   Updated: 2024/04/15 16:07:21 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_lib.h"

void	ft_compute_mandelbrot(t_fract *data)
{
	while (++data->n < data->max_iterations)
	{
		data->z_re2 = data->z_re * data->z_re;
		data->z_im2 = data->z_im * data->z_im;
		if (data->z_re2 + data->z_im2 > 10)
		{
			data->is_inside = 0;
			break ;
		}
		data->z_im = 2 * data->z_re * data->z_im + data->c_im;
		data->z_re = data->z_re2 - data->z_im2 + data->c_re;
	}
}

void	ft_compute_julia(t_fract *data)
{
	if (data->flag == 0)
	{
		data->new_re = (data->x - WIDTH / 2.0) * 4.0 / WIDTH;
		data->new_im = (data->y - HEIGHT / 2.0) * 4.0 / WIDTH;
	}
	else
	{
		data->new_re = data->min_re + (data->x * data->re_factor);
		data->new_im = data->max_im - (data->y * data->im_factor);
	}
	update_calculation_j(data);
	while (++data->n < data->max_iterations)
	{
		data->z_re2 = data->z_re * data->z_re;
		data->z_im2 = data->z_im * data->z_im;
		if (data->z_re2 + data->z_im2 > 4)
		{
			data->is_inside = 0;
			break ;
		}
		data->z_im = 2 * data->z_re * data->z_im + data->c_im;
		data->z_re = data->z_re2 - data->z_im2 + data->c_re;
	}
}

void	img_pix_put(t_fract *img, int x, int y, int color)
{
	char	*dst;

	if (x < 1 || x >= WIDTH - 1 || y < 1 || y >= HEIGHT - 1)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
