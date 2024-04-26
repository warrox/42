/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:27:24 by whamdi            #+#    #+#             */
/*   Updated: 2024/04/25 09:11:04 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_lib.h"

void	init_value(t_fract *data)
{
	data->min_re = -2.0;
	data->max_re = 1.0;
	data->min_im = -1.2;
	data->max_im = data->min_im + (data->max_re - data->min_re) * HEIGHT
		/ WIDTH;
	data->re_factor = (data->max_re - data->min_re) / (WIDTH - 1);
	data->im_factor = (data->max_im - data->min_im) / (HEIGHT - 1);
	data->zoom = 1.0;
	data->center_re = 0.0;
	data->center_im = 0.0;
	data->flag = 0;
}

void	init_mandelbrot(t_fract *data)
{
	data->center_im = 0;
	data->center_re = -0.7;
	data->re_factor = 0.003;
	data->im_factor = 0.003;
	data->min_re = data->center_re - (WIDTH * 0.5) * data->re_factor;
	data->max_im = data->center_im + (HEIGHT * 0.5) * data->im_factor;
	data->y = 0;
	data->x = 0;
	data->max_iterations = 200;
}

void	init_julia(t_fract *data)
{
	data->center_im = 0;
	data->center_re = -0.7;
	data->re_factor = 0.003;
	data->im_factor = 0.003;
	data->max_iterations = 200;
	data->c_im = 0.01;
	data->c_re = 0.285;
	data->min_re = data->center_re - (WIDTH * 0.5) * data->re_factor;
	data->max_im = data->center_im + (HEIGHT * 0.5) * data->im_factor;
	data->y = 0;
	data->x = 0;
	data->new_re = 0;
	data->new_im = 0;
	data->z_re = 0;
	data->z_re2 = 0;
	data->z_im = 0;
	data->z_im2 = 0;
}

void	init_color(t_fract *data)
{
	data->red = 0;
	data->blue = 0;
	data->green = 0;
}

void	update_calculation(t_fract *data)
{
	data->c_re = data->min_re + data->x * data->re_factor;
	data->z_re = data->c_re;
	data->z_im = data->c_im;
	data->is_inside = 1;
	data->n = 0;
}
