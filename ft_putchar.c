/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:46:00 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 20:56:56 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putchar.c
 * @brief writes the character c
 */

#include "ft_printf.h"

/**
 * @fn int	ft_putchar(char c)
 * @brief send a letter to standard out 1
 * @param[in]	c character
 * @return		c character
 */

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (c);
}
