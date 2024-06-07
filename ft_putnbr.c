/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:40:41 by athonda           #+#    #+#             */
/*   Updated: 2024/06/07 10:16:21 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr.c
 * @brief write integer
 */

#include "ft_printf.h"

/**
 * @fn int	ft_putnbr(int nb);
 * @brief display integer
 * @param[in]	nb	integer
 * @return		length of the number (including -sign)
 */

int	ft_putnbr(int nb)
{
	size_t	i;
	size_t	case1;
	size_t	case2;

	case1 = 0;
	case2 = 0;
	i = 1;
	if (nb == -2147483648)
	{
		ft_putstr("-2");
		nb = 147483648;
		case1 = 2;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		case2 = 1;
	}
	if (nb >= 10)
	{
		i = (ft_putnbr(nb / 10)) + 1;
	}
	ft_putchar('0' + nb % 10);
	return (i + case1 + case2);
}
