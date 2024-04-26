/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_lib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:36:51 by whamdi            #+#    #+#             */
/*   Updated: 2024/04/25 11:10:27 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_LIB_H
# define FRACTOL_LIB_H
# include "../Printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define WIDTH 800
# define HEIGHT 800

typedef struct s_fract
{
	double	zoom;
	double	center_re;
	double	center_im;
	int		x;
	int		y;
	double	param_1;
	double	param_2;
	int		argc;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	char	**argv;
	int		hex_color;
	int		hex_background;
	int		red;
	int		blue;
	int		green;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		flag;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;
	int		palette;
	double	c_im;
	double	c_re;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	double	new_re;
	double	new_im;
	int		is_inside;
	int		max_iterations;
	int		n;
	double	zoom_in_factor;
	double	zoom_out_factor;
}			t_fract;

/*************************** INIT FUNC ***********************/
void		init_value(t_fract *data);
void		init_mandelbrot(t_fract *data);
void		init_julia(t_fract *data);
void		init_color(t_fract *data);
/*************************** COMPUTE FUNC ********************/
void		ft_compute_mandelbrot(t_fract *data);
void		ft_compute_julia(t_fract *data);
void		update_calculation_j(t_fract *data);
void		update_calculation(t_fract *data);
void		ft_mandlebrot(t_fract *data);
void		ft_julia(t_fract *data);
int			zoom(int key_code, int mouse_x, int mouse_y, t_fract *data);
void		update_calculation_j(t_fract *data);

/*************************** COLOR FUNC ******************/
void		ft_pix_colorization(t_fract *data);
void		ft_color_in_out(t_fract *data);
void		ft_pixel_put(t_fract *data, int x, int y, int color);
void		ft_reload_black_screen(t_fract *data);
int			render(t_fract *data);
void		img_pix_put(t_fract *img, int x, int y, int color);
int			ft_extract_color(char *hex, t_fract *data);
/*************************** PARSING FUNC ***************/
int			ft_close(int keycode, t_fract *vars);
void		ft_parser(t_fract *data);
void		ft_check_param(t_fract *data, int flag);
/*************************** UTILS FUNC *****************/
double		ft_atof(const char *s, int power, int neg, t_fract *data);
int			ft_hex_to_dec(char c);
void		split_destroy(char **split);
void		ft_print_menu(void);
int			init_mlx(t_fract *data);
void		ft_atof_exit(t_fract *data);
void		ft_init_main(int argc, char **argv, t_fract *data);
#endif
