/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfilter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:14:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 23:08:12 by athonda          ###   ########.fr       */
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
	size_t	i;

	i = 0;
	if (c == 'c')
	{
		ft_putchar(va_arg(ap, int));
		i = 1;
	}
	else if (c == 's')
		i = ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		i = ft_putptr(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		i = ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			i = ft_puthexa(va_arg(ap, unsigned int), 0);
		else
			i = ft_puthexa(va_arg(ap, unsigned int), 1);
	}
	return (i);
}