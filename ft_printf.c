/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:32:30 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 22:51:17 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			ft_putchar(ptr[i]);
			count++;
		}
		i++;
	}
	va_end(ap);

	return (index + count);
}
