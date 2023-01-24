/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:35 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/24 18:41:34 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/fractol.h"
#include "./srcs/keys.h"

void	init_fractal(t_fractol *f)
{
	if (f->fractal == 1)
		init_mandelbrot(f);
	else if (f->fractal == 2)
		init_julia(f);
}

int	init_data(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		return (0);
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (!f->win_ptr)
	{
		free(f->mlx_ptr);
		return (0);
	}
	f->img.mlx_img = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.mlx_img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	init_fractal(f);
	return (1);
}