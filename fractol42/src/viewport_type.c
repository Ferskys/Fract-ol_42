/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:26:42 by fsuomins          #+#    #+#             */
/*   Updated: 2023/01/24 17:05:14 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "mlx.h"
#include "fractol.h"

void    viewport_adjust(t_viewport *v)
{
    double w;
	double h;

	w = v->xmax - v->xmin;
	h = v->ymax - v->ymin;
	if (w / h >= (float)WIN_WIDTH / WIN_HEIGHT)
	{
		v->ymin = -(w * WIN_HEIGHT / WIN_WIDTH / 2);
		v->ymax = w * WIN_HEIGHT / WIN_WIDTH / 2;
	}
	else
	{
		v->xmin = -(h * WIN_WIDTH / WIN_HEIGHT / 2);
		v->xmax = (h * WIN_WIDTH / WIN_HEIGHT / 2);
	}
}

void    viewport_reset(t_mlx *mlx)
{
	mlx->viewport.offx = 0;
	mlx->viewport.offy = 0;
	mlx->fractal->viewport(&mlx->viewport);
	viewport_adjust(&mlx->viewport);
	mlx->viewport.max = 32;
	mlx->viewport.zoom = 1.0f;
}
