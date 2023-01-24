/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:04:02 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/24 19:20:23 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "mlx.h"
#include "./srcs/fractol.h"

t_fractal	choose_fractol(void)
{
	static t_fractal array[8] = {
		{"mandelbrot", mandelbrot_viewport, mandelbrot_pixel, 0},
		{"julia", julia_viewport, julia_pixel, 1},
		{"burningship", burningship_viewport, burningship_pixel, 0},
		{NULL, NULL, NULL, 0}
	};
	return (array);
}

t_fractal	*match_all(char *str)
{
	t_fractal	*fr;
	int			i;

	fr = choose_fractol();
	i = 0;
	while (fr[i].name != NULL)
	{
		if(ft_strncmp(fr[i].name, str) == 0)
			return(&fr[i]);
		i++;
	}
	return(&fr[i]);	
}

int error(char *logic)
{
	ft_putendl(logic);
	return(1);
}

int	show_hook(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractal	*fr;

	if (argc < 2)
		return (error("error: not enough arguments"));
	fr = match_all(argv[1]);
	if (fr->name == NULL)
		return (error("error: invalid fractal name"));
	if ((mlx = init(fr)) == NULL)
		return (error("error: mlx couldn't initialize properly"));
	viewport_reset(mlx);
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, show_hook, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
