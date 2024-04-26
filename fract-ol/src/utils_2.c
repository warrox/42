/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:57:42 by whamdi            #+#    #+#             */
/*   Updated: 2024/04/25 11:14:12 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_lib.h"

void	ft_init_main(int argc, char **argv, t_fract *data)
{
	data->argv = argv;
	data->argc = argc;
	data->param_1 = 0;
	data->param_2 = 0;
}

int	init_mlx(t_fract *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		return (1);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (0);
}

void	update_calculation_j(t_fract *data)
{
	data->z_re = data->new_re;
	data->z_im = data->new_im;
	data->is_inside = 1;
	data->n = 0;
}

void	ft_atof_exit(t_fract *data)
{
	free(data);
	ft_printf("error, you should enter a correct parameter\n");
	exit(EXIT_FAILURE);
}

void	ft_check_param(t_fract *data, int flag)
{
	if (data->argc == 1 || ((ft_tolower(data->argv[1][0]) == 'm'
			&& data->argc > 3) || ((ft_tolower(data->argv[1][0]) == 'j')
		&& data->argc > 4)) || data->argv[1][1] != '\0')
	{
		free(data);
		ft_print_menu();
	}
	if (flag == 1)
		ft_atof_exit(data);
	else if (ft_tolower(data->argv[1][0]) == 'j' && data->argc == 4)
		return ;
}
