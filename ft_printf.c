/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:32:30 by athonda           #+#    #+#             */
/*   Updated: 2024/06/07 01:25:04 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t		len;
	va_list		ap;

	va_start(ap, format);
	if (ap == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			len = len + ft_printfilter(*(format + 1), ap);
			format++;
		}
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
