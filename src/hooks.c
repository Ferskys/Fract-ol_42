/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:35 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/27 19:03:39 by fsuomins         ###   ########.fr       */
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

void	color(t_fractol *f)
{
	static int colors;

	colors++;
	if(colors == 5)
		colors = 0;
	if (colors == 0)
		f->color = 265;
	else if (colors == 1)
		f->color = 1677216;
	else if (colors == 2)
		f->color = 433216;
	else if (colors == 3)
		f->color = 2377216;
	else if (colors == 4)
		f->color = 677212;
}

int		key_hook(int keycode, t_fractol *f)
{
	printf("tecla: %d\n", keycode);
	if (keycode == 65307)
		close_win(f);
	else if (keycode == 'a')
		f->it_max += 50;
	else if (keycode == 'd')
		f->it_max -= 50;
	else if (keycode == 'r')
		fract_init(f);
	else if (keycode == 'c')
		color(f);
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

// void	ft_dezoom(int x, int y, t_fractol *f)
// {
// 	// f->x1 = (x / f->zoom + f->x1)  - (x / (f->zoom / 1.3));
// 	// f->y1 = (y / f->zoom + f->y1) - (y / (f->zoom / 1.3));
// 	// f->zoom /= 1.3;
// 	// f->it_max--;
// }

// int		mouse_hook(int mousecode, int x, int y, t_fractol *f)
// {
// 	// if (mousecode == 4 || mousecode == 1)
// 	// 	ft_zoom(x, y, f);
// 	// else if (mousecode == 5 || mousecode == 2)
// 	// 	ft_dezoom(x, y, f);
// 	// draw_frac(f);
// 	// return (0);
// }