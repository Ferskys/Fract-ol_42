/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:55:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/27 15:27:01 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_mouse(int x, int y, t_fractol *f)
{
	if (f->fract == 1 && f->julia_mouse == 1)
	{
		f->c_r = x * 2;
		f->c_i = y * 2 - 800;
		//fract_math(f);
	}
	return (0);
}

void	julia_init(t_fractol *f)
{
	f->it_max = 50;
	f->zoom = 200;
	f->x1 = -2.0;
	f->y1 = -1.9;
	f->color = 265;
	f->c_r = 0.285;
	f->c_i = 0.01;
	f->julia_mouse = 1;
}

void	julia_math(t_fractol *f)
{
	f->z_r = f->x / f->zoom + f->x1;
	f->z_i = f->y / f->zoom + f->y1;
	f->it = 0;
	while (f->z_r * f->z_r + f->z_i
			* f->z_i < 4 && f->it < f->it_max)
	{
		f->tmp = f->z_r;
		f->z_r = f->z_r * f->z_r -
			f->z_i * f->z_i - 0.8 + (f->c_r / WIDTH);
		f->z_i = 2 * f->z_i * f->tmp + f->c_i / WIDTH;
		f->it++;
	}
	if (f->it == f->it_max)
		put_pxl_to_img(f, f->x, f->y, 0x000000);
	else
		put_pxl_to_img(f, f->x, f->y, (f->color * f->it));
}

void	*julia(void *tab)
{
	int		tmp;
	t_fractol	*f;

	f = (t_fractol *)tab;
	f->x = 0;
	tmp = f->y;
	while (f->x < WIDTH)
	{
		f->y = tmp;
		while (f->y < f->y_max)
		{
			julia_math(f);
			f->y++;
		}
		f->x++;
	}
	return (tab);
}