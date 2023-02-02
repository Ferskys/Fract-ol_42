/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:53:42 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/02 13:47:04 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

void	tricorn_init(t_fractol *f)
{
	f->min_re = -2.1;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = (f->max_re - f->min_re) + f->min_im;
	f->it_max = 100;
	f->color = 265;
}

void	tricorn_math(t_fractol *f, double x, double y)
{
	int	inter;

	f->c_r = f-> min_re + (x * (f->max_re - f->min_re)) / WIDTH;
	f->c_i = f-> min_im + (y * (f->max_im - f->min_im)) / HEIGTH;
	f->z_r = 0;
	f->z_i = 0;
	inter = 0;
	f->tmp = 0;
	while (inter < f->it_max)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = -2 * f->z_i * f->z_r + f->c_i;
		f->z_r = f->tmp;
		if (f->z_r * f->z_r + f->z_i * f->z_i > 4)
			break ;
		inter++;
	}
	if (inter == f->it_max)
		put_pxl_to_img(f, x, y, 0x22b222);
	else
		put_pxl_to_img(f, x, y, (inter * f->color * inter));
}

void	tricorn(t_fractol *f)
{
	double		x;
	double		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			tricorn_math(f, y, x);
			y++;
		}
		x++;
	}
}
