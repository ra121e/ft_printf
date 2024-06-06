/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:32:30 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 14:48:34 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfilter(char c, va_list ap)
{
	size_t	i;

	i = 0;
	if (c == 'c')
	{
		i = ft_printchar(va_arg(ap, int));
	}
	else if (c == 's')
	{
		i = ft_printstr(va_arg(ap, char *));
	}
	else if (c == 'p')
	{
		ft_printchar('0');
		ft_printchar('x');
		i = ft_printpointer(va_arg(ap, unsigned long long));
		i = i + 2;
	}
	else if (c == 'd' || c == 'i')
	{
		i = ft_printnbr(va_arg(ap, int));
	}
	else if (c == 'u')
	{
		i = ft_printunbr(va_arg(ap, unsigned int));
	}
	else if (c == 'x' || c == 'X')
	{
		i = ft_printhexa(va_arg(ap, unsigned int), c);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	size_t		index;
	const char	*ptr;
	va_list		ap;
	size_t		count;

	ptr = format;
	va_start(ap, format);
	if (ap == NULL)
		return (-1);
	index = 0;
	count = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			index = index + ft_printfilter(ptr[i + 1], ap);
			i++;
		}
		else
		{
			ft_printchar(ptr[i]);
			count++;
		}
		i++;
	}
	va_end(ap);

	return (index + count);
}
