/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:20:25 by fsuomins          #+#    #+#             */
/*   Updated: 2022/09/27 20:20:47 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*pos;
	size_t	tot_size;
	int		fill_byte;

	tot_size = nmemb * size;
	fill_byte = 0;
	if (!nmemb || !size || size > INT_MAX / nmemb)
		return (NULL);
	pos = malloc(tot_size);
	if (!pos)
		return (NULL);
	ft_memset (pos, fill_byte, tot_size);
	return ((void *)pos);
}
