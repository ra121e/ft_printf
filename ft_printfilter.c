/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfilter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:14:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/07 00:37:28 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printfilter.c
 * @brief filtering specifier and call each function
 */

#include "ft_printf.h"

/**
 * @fn int	ft_printfilter(char c, va_list ap)
 * @brief take character after % from text, and send argument to display
 * @param[in]	c character of specifier behind of %
 * @param[in]	ap va_list storing each variadic argument
 * @return		length of each argument
 */

int	ft_printfilter(char c, va_list ap)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(ap, int));
		return (1);
	}
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(ap, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthexa(va_arg(ap, unsigned int), 1));
	else if (c == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}
