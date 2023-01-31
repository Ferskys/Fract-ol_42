/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:04:36 by fsuomins          #+#    #+#             */
/*   Updated: 2022/09/16 21:26:30 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

// int main()
// {
// 	int number = 51; //aqui tem que sair 1 //
// 	int notnumber = 'a'; // sai 0 
// 	printf("%i\n", ft_isdigit(number));
// 	printf("%i\n", ft_isdigit(notnumber));
// 	return(0);
// }*/