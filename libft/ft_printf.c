/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:57:20 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/02 14:01:58 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		ret;

	va_start(arg, format);
	i = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ret += search(format[i + 1], arg);
			i += 2;
		}
		else
		{
			ret += ft_putchar(format[i]);
			i++;
		}
	}
	return (ret);
}

int	search(char format, va_list arg)
{
	int	ret;

	ret = 0;
	if (format == 'i' || format == 'd')
		ret += ft_putnbr(va_arg(arg, int));
	else if (format == 's')
		ret += ft_putstr(va_arg(arg, char *));
	else if (format == '%')
		ret += ft_putchar('%');
	else if (format == 'c')
		ret += ft_putchar(va_arg(arg, unsigned int));
	else if (format == 'u')
		ret += ft_putnbru(va_arg(arg, unsigned int));
	else if (format == 'p')
		ret += pointer(va_arg(arg, unsigned long));
	else if (format == 'X')
		ret += dex(va_arg(arg, unsigned int), 0, 0);
	else if (format == 'x')
		ret += dexs(va_arg(arg, unsigned int), 0, 0);
	return (ret);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putnbru(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n < 10)
	{
		ret += ft_putchar(n + 48);
		return (ret);
	}
	else
	{
		ret += ft_putnbru(n / 10);
		ret += ft_putnbru(n % 10);
	}
	return (ret);
}
