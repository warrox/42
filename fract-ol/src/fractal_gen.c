/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:50:48 by whamdi            #+#    #+#             */
/*   Updated: 2024/04/15 16:06:17 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_lib.h"

int	ft_close(int keycode, t_fract *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_clear_window(vars->mlx, vars->mlx_win);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free(vars);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	zoom(int button, int x, int y, t_fract *data)
{
	double	zoom_factor;
	double	mouse_x;
	double	mouse_y;

	data->zoom_in_factor = 0.8;
	data->zoom_out_factor = 1.2;
	if (button == 4)
		zoom_factor = data->zoom_in_factor;
	else
		zoom_factor = data->zoom_out_factor;
	mouse_x = data->min_re + ((double)x * data->re_factor);
	mouse_y = data->max_im - ((double)y * data->im_factor);
	data->re_factor *= zoom_factor;
	data->im_factor *= zoom_factor;
	data->center_re = mouse_x;
	data->center_im = mouse_y;
	data->min_re = data->center_re - WIDTH * 0.5 * data->re_factor;
	data->max_im = data->center_im + HEIGHT * 0.5 * data->im_factor;
	data->flag = 1;
	ft_reload_black_screen(data);
	if (ft_tolower(data->argv[1][0]) == 'm')
		ft_mandlebrot(data);
	else if (ft_tolower(data->argv[1][0]) == 'j')
		ft_julia(data);
	return (0);
}

void	ft_reload_black_screen(t_fract *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT - 1)
	{
		x = 0;
		while (x < WIDTH)
		{
			img_pix_put(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_julia(t_fract *data)
{
	if (data->flag == 0)
		init_julia(data);
	else
	{
		data->y = 0;
		data->x = 0;
	}
	if (data->argc > 3)
	{
		data->c_im = data->param_1;
		data->c_re = data->param_2;
	}
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			ft_compute_julia(data);
			ft_color_in_out(data);
			++data->x;
		}
		++data->y;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_mandlebrot(t_fract *data)
{
	if (data->flag == 0)
		init_mandelbrot(data);
	else
	{
		data->y = 0;
		data->x = 0;
	}
	while (data->y < HEIGHT)
	{
		data->c_im = data->max_im - data->y * data->im_factor;
		data->x = 0;
		while (data->x < WIDTH)
		{
			update_calculation(data);
			ft_compute_mandelbrot(data);
			ft_color_in_out(data);
			++data->x;
		}
		++data->y;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
