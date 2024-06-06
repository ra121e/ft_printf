/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfunction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:59:15 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 14:40:17 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printpointer(unsigned long long addrs)
{
	char	*hexabase;
	int		i;

	hexabase = "0123456789abcdef";
	i = 1;
	if (addrs == 0)
	{
		ft_printstr("(nil)");
		i = 5;
	}
	if (addrs > 16)
	{
		i = i + ft_printpointer(addrs / 16);
	}
	ft_printchar(hexabase[addrs % 16]);
	return (i);
}

int	ft_printnbr(int nb)
{
	size_t	i;
	size_t	case1;
	size_t	case2;

	case1 = 0;
	case2 = 0;
	i = 1;
	if (nb == -2147483648)
	{
		ft_printstr("-2");
		nb = 147483648;
		case1 = 2;
	}
	if (nb < 0)
	{
		ft_printchar('-');
		nb = nb * -1;
		case2 = 1;
	}
	if (nb > 10)
	{
		i = (ft_printnbr(nb / 10)) + 1;
	}
	ft_printchar('0' + nb % 10);
	return (i + case1 + case2);
}

int	ft_printhexa(unsigned int nb, char specifier)
{
	char	*hexabase_small;
	char	*hexabase_big;
	int		i;

	hexabase_small = "0123456789abcdef";
	hexabase_big = "0123456789ABCDEF";
	i = 1;
	if (nb > 16)
	{
		i = i + ft_printhexa(nb / 16, specifier);
	}
	if (specifier == 'x')
	{
		ft_printchar(hexabase_small[nb % 16]);
	}
	else if (specifier == 'X')
	{
		ft_printchar(hexabase_big[nb % 16]);
	}
	return (i);
}
