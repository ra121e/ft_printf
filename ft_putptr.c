/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:04:43 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 22:11:49 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putptr.c
 * @brief display address at standard out
*/

#include "ft_printf.h"

/**
 * @fn int	ft_putptr(void *p)
 * @brief to show address as hexadecimal number with 0x prefix
 * @param[in]	*p address
 * @return		length of numbers including prefix 2
 */

int	ft_putptr(void	*p)
{
	int	len;
	unsigned long long	addrs;

	len = 0;
	addrs = (unsigned long long)p;
	len = len + ft_putstr("0x");
	len = len + ft_puthexa(addrs, 0);
	return (len);
}
