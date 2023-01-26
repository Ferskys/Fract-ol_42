/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:38:15 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/26 19:48:32 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		close_win(void)
{
	exit(1);
	return (0);
}

void	put_pxl_to_img(t_fractol *f, int x, int y, int color)
{
	if (f->x < WIDTH && f->y < WIDTH)
	{
		color = mlx_get_color_value(f->mlx, color);
		ft_memcpy(f->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	msg(t_fractol *f)
{
	char	*message;
	char	*nb;

	nb = ft_itoa(f->it_max);
	message = ft_strjoin("iterations : ", nb);
	mlx_string_put(f->mlx, f->win, 10, 10, 0xFFFFFF, message);
	ft_strdel(&message);
	ft_strdel(&nb);
}