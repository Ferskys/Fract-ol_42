/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:04:02 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/01 17:00:26 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

int	draw_frac(t_fractol *f)
{
	if (f->fract == 1)
		mandelbrot (f);
	else if (f->fract == 2)
		julia (f);
	else if (f->fract == 3)
		tricorn (f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

void	fract_init(t_fractol *f)
{
	if (f->fract == 1)
		mandelbrot_init (f);
	else if (f->fract == 2)
		julia_init (f);
	else if (f->fract == 3)
		tricorn_init (f);
}

void	mlx_win_init(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGTH, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGTH);
	f->img_ptr = mlx_get_data_addr(f->img, &f->bpp, &f->sl, &f->endian);
}

int	check_arg(t_fractol *f, int argc, char **argv)
{
	if (argc == 2 && ft_strncmp("mandelbrot", argv[1], 10) == 0)
	{
		f->fract = 1;
		return (1);
	}
	else if (argc == 4 && ft_strncmp("julia", argv[1], 5) == 0
		&& ft_atof(argv[2]) >= -2.0 && ft_atof(argv[2]) <= 2.0
		&& ft_atof(argv[3]) >= -2.0 && ft_atof(argv[3]) <= 2.0)
	{
		f->fract = 2;
		f->arg_re = ft_atof(argv[2]);
		f->arg_im = ft_atof(argv[3]);
		return (1);
	}
	else if (argc == 2 && ft_strncmp("tricorn_bonus", argv[1], 14) == 0)
	{
		f->fract = 3;
		return (1);
	}
	else
		ft_putendl("😞: /fractol \"mandelbrot\"or\"julia [v_re] [v_im]\"");
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	f.x = 0;
	f.y = 0;
	if (!check_arg(&f, argc, argv))
	{
		exit(0);
	}
	mlx_win_init(&f);
	fract_init(&f);
	mlx_loop_hook(f.mlx, draw_frac, &f);
	mlx_hook(f.win, 17, 0L, close_win, &f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_hook(f.win, 4, 1L << 2, &mouse_zoom, &f);
	mlx_loop(f.mlx);
	return (0);
}
