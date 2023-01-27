/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:35 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/27 15:26:17 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook2(int keycode, t_fractol *f)
{
	if (keycode == 19)
		f->color = 2050;
	else if (keycode == 20)
		f->color = 265;
	else if (keycode == 35)
		f->julia_mouse = !f->julia_mouse;
	else if (keycode == 34)
		f->show_text = !f->show_text;
	return (0);
}

int		key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		f->it_max += 50;
	else if (keycode == 78)
		f->it_max -= 50;
	else if (keycode == 123)
		f->x1 -= 30 / f->zoom;
	else if (keycode == 124)
		f->x1 += 30 / f->zoom;
	else if (keycode == 125)
		f->y1 += 30 / f->zoom;
	else if (keycode == 126)
		f->y1 -= 30 / f->zoom;
	else if (keycode == 49)
		fract_init(f);
	else if (keycode == 18)
		f->color = 1677216;
	key_hook2(keycode, f);
	draw_frac(f);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *f)
{
	f->x1 = (x / f->zoom + f->x1) - (x / (f->zoom * 1.3));
	f->y1 = (y / f->zoom + f->y1) - (y / (f->zoom * 1.3));
	f->zoom *= 1.3;
	f->it_max++;
}

void	ft_dezoom(int x, int y, t_fractol *f)
{
	f->x1 = (x / f->zoom + f->x1)  - (x / (f->zoom / 1.3));
	f->y1 = (y / f->zoom + f->y1) - (y / (f->zoom / 1.3));
	f->zoom /= 1.3;
	f->it_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, f);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, f);
	draw_frac(f);
	return (0);
}