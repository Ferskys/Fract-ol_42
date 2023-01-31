/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:55:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/31 19:07:18 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	julia_init(t_fractol *f)
{
	f->zoom = 200;
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = (f->max_re - f->min_re) * HEIGTH / WIDTH + f->min_im;
	f->it_max = 250;
	f->color = 265;
}

void	julia_math(t_fractol *f, double x, double y)
{
	int	inter;


	f->c_r = f-> min_re + (x * (f->max_re - f->min_re)) / WIDTH;
	f->c_i = f-> min_im + (y * (f->max_im - f->min_im)) / HEIGTH;

	f->z_r = f->c_r;
	f->z_i = f->c_i;
	inter = 0;
	f->tmp = 0;
	while (inter < f->it_max)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->arg_re;
		f->z_i = 2 * f->z_i * f->z_r - f->arg_im;
		f->z_r = f->tmp;
		if(f->z_r * f->z_r + f->z_i * f->z_i > 4)
			break;
		inter++;
	}
	if (inter == f->it_max)
		put_pxl_to_img(f, x, y, 0x000000);
	else
		put_pxl_to_img(f, x, y, (inter * f->color * inter));
}

void	*julia(t_fractol *f)
{
	double x; 
	double y;
	
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			julia_math(f, y, x);
			y++;
		}
		x++;
	}
	return (0);
}