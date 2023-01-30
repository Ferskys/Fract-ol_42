/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:04:02 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/30 18:42:40 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_frac(t_fractol *f)
{
	if(f->fract == 1)
		mandelbrot(f);
	if(f->fract == 2)
		julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return(0);
}

void	fract_init(t_fractol *f)
{
	if (f->fract == 1)
		mandelbrot_init(f);
	else if (f->fract == 2)
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
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		f->fract = 1;
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		f->fract = 2;
	else
	{
		ft_putendl("Use: /fractol \"mandelbrot\"or\"julia[v_re] [v_im]\"");
		return (0);
	}
	return (1);
}

int	check_julia(int argc, char **argv, t_fractol *f)
{
	if (argc != 4)
		return (0);
	f->arg_re = ft_atof(argv[2]);
	if (f->arg_re < -2.0 || f->arg_re > 2.0)
		return (0);
	if (!(check_double(argv[2])))
		return (0);
	if (!check_double(argv[3]))
		return (0);
	f->arg_re = ft_atof(argv[2]);
	f->arg_im = ft_atof(argv[3]);
	if (f->arg_im < -2 || f->arg_im > 2)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2 || argc > 4)
	{
		ft_putendl("Use: /fractol \"mandelbrot\"or\"julia[v_re] [v_im]\"");
		return (-1);
	}
	f.arg_re =ft_atof(argv[2]);
	f.arg_im =ft_atof(argv[3]);
	if ((frac_comp(argv, &f)) == 0)
		return (-1);
	mlx_win_init(&f);
	fract_init(&f);
	mlx_loop_hook(f.mlx, draw_frac, &f);
	//mlx_hook(f.win, 6, 1L < 6, mouse_julia, &f);
	mlx_hook(f.win, 17, 0L, close_win, &f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_hook(f.win, 4, 1L << 2, &mouse_zoom, &f);
	mlx_loop(f.mlx);
	return (0);
}