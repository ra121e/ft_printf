/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:32:30 by athonda           #+#    #+#             */
/*   Updated: 2024/06/07 15:22:13 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @brief To take several arguments and send va_list to ft_printfilter
 */

#include "ft_printf.h"

/**
 * @fn int	ft_printf(const char *format, ...)
 * @brief genarate argument point by va_ series macros, and detect %
 * @param[in]	format	char pointer for the static argument
 * @return 	length of the total text after converting specifier to arges
 */

int	ft_printf(const char *format, ...)
{
	size_t		len;
	va_list		ap;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	len = 0;
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
