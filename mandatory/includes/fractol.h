/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:57:15 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/02 15:11:14 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <X11/keysym.h>
# include <mlx.h>
# include <math.h>
# define WIDTH 600
# define HEIGTH 600

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_ptr;
	int		endian;
	int		sl;
	int		bpp;
	int		fract;
	int		color;
	int		x;
	int		y;
	int		y_max;
	int		inter;
	int		it_max;
	double	zoom;
	double	x1;
	double	y1;
	double	arg_re;
	double	arg_im;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	double	max_im;
	double	min_im;
	double	max_re;
	double	min_re;
}	t_fractol;

int		check_double(const char *str);
int		check_arg(t_fractol *f, int argc, char **argv);

double	ft_atof(const char *str);
int		key_hook(int keycode, t_fractol *f);

void	ft_zoom(int x, int y, t_fractol *f);
void	mandelbrot_init(t_fractol *f);
void	mandelbrot_math(t_fractol *f, double x, double y);
void	mandelbrot(t_fractol *f);

int		check_julia(int argc, char **argv, t_fractol *f);
void	julia_init(t_fractol *f);
void	julia_math(t_fractol *f, double x, double y);
void	*julia(t_fractol *f);

int		mouse_zoom(int key, int x, int y, t_fractol *f);
int		close_win(t_fractol *f);
void	put_pxl_to_img(t_fractol *f, int x, int y, int color);

int		draw_frac(t_fractol *f);
void	fract_init(t_fractol *f);
void	mlx_win_init(t_fractol *f);
int		main(int argc, char **argv);

void	color(t_fractol *f);

#endif