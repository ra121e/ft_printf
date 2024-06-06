/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:54:01 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 22:59:45 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_puthexa.c
 * @brief write integer by hexa base
 */

#include "ft_printf.h"

/**
 * @fn int	ft_puthexa(unsigned int nb, int hexatype)
 * @brief display the number by 16(hexa) base
 * @param[in]	nb integer
 * @param[in]	hexatype integer 0 or 1
 * @return		length of the number
 */

int	ft_puthexa(unsigned int nb, int hexatype)
{
	char	*hexabase;
	int		i;

	if (hexatype == 0)
		hexabase = "0123456789abcdef";
	else
		hexabase = "0123456789ABCDEF";
	i = 1;
	if (nb > 16)
	{
		i = i + ft_puthexa(nb / 16, hexatype);
	}
	ft_putchar(hexabase[nb % 16]);
	return (i);
}
