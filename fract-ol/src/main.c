/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:36:57 by whamdi            #+#    #+#             */
/*   Updated: 2024/04/25 11:10:06 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_lib.h"

void	ft_pixel_put(t_fract *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_print_menu(void)
{
	ft_printf("-------------\n");
	ft_printf("1.\t Choose M(Mandlebrot) or J(Julia)\n");
	ft_printf("2.\t For Julia you can add a");
	ft_printf(" Position on x & y (float) between 0 to 1 ex : 0.35 0.76\n");
	ft_printf("3.\t for Mandelbrot you can choose Hexadecimal to get a");
	ft_printf("new background color ex : EB34D8\n");
	ft_printf("-------------\n");
	exit(EXIT_FAILURE);
}

int	render(t_fract *data)
{
	if (data->mlx_win != NULL)
	{
		if (data->is_inside)
		{
			img_pix_put(data, data->x, data->y, data->hex_background);
		}
		else
		{
			img_pix_put(data, data->x, data->y, data->hex_color);
		}
	}
	return (0);
}

int	close_window(t_fract *vars)
{
	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
	exit(EXIT_SUCCESS);
	return (1);
}

int	main(int argc, char **argv, char *envp[])
{
	t_fract	*data;

	if (!*envp)
		return (1);
	data = malloc(sizeof(t_fract));
	if (!data)
		return (0);
	ft_init_main(argc, argv, data);
	ft_check_param(data, 0);
	ft_parser(data);
	init_value(data);
	init_mlx(data);
	if (ft_tolower(data->argv[1][0]) == 'm')
		ft_mandlebrot(data);
	if (data->param_1 >= 1 || data->param_2 >= 1)
		ft_atof_exit(data);
	if (ft_tolower(data->argv[1][0]) == 'j')
		ft_julia(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_mouse_hook(data->mlx_win, zoom, data);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &ft_close, data);
	mlx_loop(data->mlx);
	free(data);
}
