/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:45:44 by fsuomins          #+#    #+#             */
/*   Updated: 2022/09/27 20:34:58 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	p = (char *)s1;
	if (ft_strlen(s2) == 0 || s1 == s2)
		return (p);
	while (p[i] != '\0' && i < len)
	{
		j = 0;
		while (p[i + j] != '\0' && s2[j] != '\0'
			&& p[i + j] == s2[j] && i + j < len)
			j++;
		if (j == ft_strlen(s2))
			return (p + i);
		i++;
	}
	return (0);
}
