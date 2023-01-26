/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:53:42 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/26 19:48:40 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_init(t_fractol *f)
{
	f->it_max = 50;
	f->zoom = 300;
	f->x1 = -2.05;
	f->y1 = -1.3;
	f->color = 265;
}

void	mandelbrot_math(t_fractol *f)
{
	f->c_r = f->x / f->zoom + f->x1;
	f->c_i = f->y / f->zoom + f->y1;
	f->z_r = 0;
	f->z_i = 0;
	f->it = 0;
	while (f->z_r * f->z_r + f->z_i *
			f->z_i < 4 && f->it < f->it_max)
	{
		f->tmp = f->z_r;
		f->z_r = f->z_r * f->z_r -
			f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * f->tmp + f->c_i;
		f->it++;
	}
	if (f->it == f->it_max)
		put_pxl_to_img(f, f->x, f->y, 0x000000);
	else
		put_pxl_to_img(f, f->x, f->y, (f->color * f->it));
}

void	*mandelbrot(void *tab)
{
	t_fractol	*f;
	int		tmp;

	f = (t_fractol *)tab;
	f->x = 0;
	tmp = f->y;
	while (f->x < WIDTH)
	{
		f->y = tmp; 
		while (f->y < f->y_max)
		{
			mandelbrot_math(f);
			f->y++;
		}
		f->x++;
	}
	return (tab);
}

void	mandelbrot_pthread(t_fractol *f)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)f, sizeof(t_fractol));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}