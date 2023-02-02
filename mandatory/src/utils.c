/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:38:15 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/02 14:09:52 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
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

int	mouse_zoom(int key, int x, int y, t_fractol *f)
{
	x = 1;
	y = 1;
	if (key == 4 && x)
	{
		f->min_re -= f->min_re * 0.1;
		f->max_re -= f->max_re * 0.1;
		f->min_im -= f->min_im * 0.1;
		f->max_im -= f->max_im * 0.1;
	}
	if (key == 5 && y)
	{
		f->min_re += f->min_re * 0.1;
		f->max_re += f->max_re * 0.1;
		f->min_im += f->min_im * 0.1;
		f->max_im += f->max_im * 0.1;
	}
	return (1);
}

int	check_double(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '.')
		return (0);
	while (*str && *str != '.')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (*str == '.')
	{
		if (!ft_isdigit(*(str + 1)))
			return (0);
		str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
	}
	return (1);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	double	power;
	int		i;

	sign = 1;
	result = 0;
	power = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i++] - '0';
		power *= 10;
	}
	return (sign * result / power);
}
