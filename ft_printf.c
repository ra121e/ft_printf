/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:32:30 by athonda           #+#    #+#             */
/*   Updated: 2024/06/05 11:45:29 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_filter(char c, va_list ap)
{
	size_t	i;

	if (c == 'c')
	{
		i = ft_putchar(va_arg(ap, int));
	}
	return (i);
}


int	ft_printf(const char *format, ...)
{
	int			i;
	size_t		index;
	const char	*ptr;
	va_list		ap;

	ptr = format;
	va_start(ap, format);
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			index = ft_filter(ptr[i + 1], ap);
			i++;
		}
		else
		{
			ft_putchar(ptr[i]);
		}
		i++;
	}
	va_end(ap);

	return (index);
}

int	main(void)
{
	size_t	i;
	char	c;

	c = 'a';
	i = ft_printf("12345%c\n", c);
	printf("return ft_printf: %ld\n", i);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	i = printf("12345%c\n", c);
	printf("return of original printf: %ld\n", i);
	return (0);
}