/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:35 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/02 14:08:41 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

void	color(t_fractol *f)
{
	static int	colors;

	colors++;
	if (colors == 6)
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
	else if (colors == 5)
		f->color = 37212;
}

int	key_hook(int keycode, t_fractol *f)
{
	ft_printf("tecla: %d\n", keycode);
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
