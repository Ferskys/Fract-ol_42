/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:04:02 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/27 18:40:35 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_frac(t_fractol *f)
{
	mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return(0);
}

void	fract_init(t_fractol *f)
{
	if (f->fract == 0)
		mandelbrot_init(f);
	else if (f->fract == 1)
		julia_init(f);
	//else if (f->fract == 2)
	//	burningship_init(f);
}

void	mlx_win_init(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGTH , "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGTH);
	f->img_ptr = mlx_get_data_addr(f->img,
			&f->bpp, &f->sl, &f->endian);
}

int		frac_comp(char **argv, t_fractol *f)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		f->fract = 0;
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		f->fract = 1;
	else
	{
		ft_putendl("Usage: /fractol \"mandelbrot\", \"julia\"");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2 || argc > 4)
	{
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\"");
		return (-1);
	}
	if ((frac_comp(argv, &f)) == 0)
		return (-1);
	mlx_win_init(&f);
	fract_init(&f);
	mlx_loop_hook(f.mlx, draw_frac, &f);
	//mlx_hook(f.win, 6, 1L < 6, julia_mouse, &f);
	mlx_hook(f.win, 17, 0L, close_win, &f);
	mlx_key_hook(f.win, key_hook, &f);
	//mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}