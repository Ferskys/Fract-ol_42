/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:04:02 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/26 20:24:54 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	math_fract(t_fractol *f)
{
	if (f->it_max < 0)
		f->it_max = 0;
	if (f->fract == 0)
		mandelbrot_pthread(f);
	else if (f->fract == 1)
		julia_pthread(f);
	else if (f->fract == 2)
		burningship_pthread(f);
	if (f->show_text)
		msg(f);
}

void	fract_init(t_fractol *f)
{
	if (f->fract == 0)
		mandelbrot_init(f);
	else if (f->fract == 1)
		julia_init(f);
	else if (f->fract == 2)
		burningship_init(f);
	math_fract(f);
}

void	mlx_win_init(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, WIDTH, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, WIDTH);
	f->img_ptr = mlx_get_f_addr(f->img,
			&f->bpp, &f->sl, &f->endian);
}

int		frac_comp(char **argv, t_fractol *f)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		f->fract = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		f->fract = 1;
	else
	{
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\"");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_fractol	*f;

	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	if (argc == 2)
	{
		mlx_win_init(f);
		if ((frac_comp(argv, f)) == 0)
			return (0);
		fract_init(f);
		mlx_hook(f->win, 6, 1L < 6, julia_mouse, f);
		mlx_hook(f->win, 17, 0L, close_win, f);
		mlx_key_hook(f->win, key_hook, f);
		mlx_mouse_hook(f->win, mouse_hook, f);
		mlx_loop(f->mlx);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\"");
	return (0);
}