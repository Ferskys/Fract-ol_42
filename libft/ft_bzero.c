/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:31:39 by fsuomins          #+#    #+#             */
/*   Updated: 2022/09/27 19:38:55 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*clean;

	clean = (char *)s;
	while (n != '\0')
	{
		*clean++ = 0;
		n--;
	}
}

// int main ()
// {
//     char word[] = "palavra";
//     int size = 7;
//     ft_bzero(word, size);
//     printf(":%s:\n", word);
//     return(0);
// }