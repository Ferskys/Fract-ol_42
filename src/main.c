/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:04:02 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/26 15:53:25 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fract_calc(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 0)
		mandelbrot_pthread(data);
	else if (data->fract == 1)
		julia_pthread(data);
	else if (data->fract == 2)
		burningship_pthread(data);
	if (data->show_text)
		put_text(data);
}

void	fract_init(t_fractol *data)
{
	if (data->fract == 0)
		mandelbrot_init(data);
	else if (data->fract == 1)
		julia_init(data);
	else if (data->fract == 2)
		burningship_init(data);
	fract_calc(data);
}

void	mlx_win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
}

int		fract_comp(char **av, t_fractol *data)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		data->fract = 1;
	else if (ft_strcmp(av[1], "burningship") == 0)
		data->fract = 2;
	else
	{
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
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
		if ((fract_comp(argv, f)) == 0)
			return (0);
		fract_init(f);
		mlx_hook(f->win, 6, 1L < 6, mouse_julia, f);
		mlx_hook(f->win, 17, 0L, ft_close, f);
		mlx_key_hook(f->win, key_hook, f);
		mlx_mouse_hook(f->win, mouse_hook, f);
		mlx_loop(f->mlx);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
	return (0);
}