/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:48:05 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 22:59:57 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putunbr.c
 * @brief write number
 */

#include "ft_printf.h"

/**
 * @fn int	ft_putunbr(unsigned int nb)
 * @brief display unsigned integer
 * @param[in]	nb unsigned integer
 * @return		length of the number
 * @note %u of printf requires unsigned int
 */

int	ft_putunbr(unsigned int nb)
{
	size_t	i;

	i = 1;
	if (nb > 10)
	{
		i = (ft_putunbr(nb / 10)) + 1;
	}
	ft_putchar('0' + nb % 10);
	return (i);
}
