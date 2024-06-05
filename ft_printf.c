/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:32:30 by athonda           #+#    #+#             */
/*   Updated: 2024/06/05 21:45:00 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

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
	if (addrs > 16)
	{
		i = i + ft_printpointer(addrs / 16);
	}
	ft_printchar(hexabase[addrs % 16]);
	return (i);
}

int	ft_printnbr(int	nb)
{
	size_t	i;

	i = 1;
	if (nb == -2147483648)
	{
		ft_printchar('-');
		ft_printchar('2');
		nb = 147483648;
		i = 2;
	}
	if (nb < 0)
	{
		ft_printchar('-');
		nb = nb * -1;
		i = 1;
	}
	if (nb > 10)
	{
		i = (ft_printnbr(nb / 10)) + 1;
	}
	ft_printchar('0' + nb % 10);
	return (i);
}

int	ft_printhexa(unsigned int nb, char specifier)
{
	char	*hexabase_small;
	char	*hexabase_big;
	int		i;

	hexabase_small = "0123456789abcdef";
	hexabase_big = "0123456789ABCDEF";
	i = 1;
	if (nb < 0)
	{
		ft_printchar('-');
		nb = nb * -1;
	}
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

int	ft_filter(char c, va_list ap)
{
	size_t	i;

	i = 0;
	if (c == 'c')
	{
		i = ft_printchar(va_arg(ap, int));
	}
	else if (c == 's')
	{
		i = ft_printstr(va_arg(ap, char *));
	}
	else if (c == 'p')
	{
		ft_printchar('0');
		ft_printchar('x');
		i = ft_printpointer(va_arg(ap, unsigned long long));
		i = i + 2;
	}
	else if (c == 'd' || c == 'i')
	{
		i = ft_printnbr(va_arg(ap, int));
	}
	else if (c == 'u')
	{
		i = ft_printnbr(va_arg(ap, unsigned int));
	}
	else if (c == 'x' || c == 'X')
	{
		i = ft_printhexa(va_arg(ap, unsigned int), c);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	size_t		index;
	const char	*ptr;
	va_list		ap;
	size_t		count;

	ptr = format;
	va_start(ap, format);
	index = 0;
	count = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			index = index + ft_filter(ptr[i + 1], ap);
			i++;
		}
		else
		{
			ft_printchar(ptr[i]);
			count++;
		}
		i++;
	}
	va_end(ap);

	return (index + count);
}

int	main(void)
{
	size_t	i;
	char	c;
	char	*str;
	char	*p;
	int		d;
	unsigned int	x;
	unsigned int	u;
	unsigned int	X;

	c = 'a';
	printf("-------------------------------------------------\n");
	printf("here is test for char c\n");
	printf("c is 'a', and text is 12345%%c\n");
	printf("-------------------------------------------------\n");
	i = ft_printf("12345%c", c);
	printf("\n");
	printf("return ft_printf: %ld\n", i);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	i = printf("12345%c", c);
	printf("\n");
	printf("return of original printf: %ld\n", i);
	printf("the number of return means length of text 5 letters and %% and c\n");

	str = "42Singapore";
	printf("-------------------------------------------------\n");
	printf("here is test for char *s\n");
	printf("str is 42Singapore, and text is 12345%%s\n");
	printf("-------------------------------------------------\n");
	i = ft_printf("12345%s", str);
	printf("\n");
	printf("return ft_printf: %ld\n", i);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	i = printf("12345%s", str);
	printf("\n");
	printf("return of original printf: %ld\n", i);
	printf("17 means text is 5, and %%, str is 11 \n");

	printf("-------------------------------------------------\n");
	printf("here is mix test of char c and char *s\n");
	printf("c is 'a', and text is 12345%%c890%%s\n");
	printf("str is 42Singapore, and text is 12345%%c890%%s\n");
	printf("-------------------------------------------------\n");
	i = ft_printf("12345%c7890%s", c, str);
	printf("\n");
	printf("return ft_printf: %ld\n", i);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	i = printf("12345%c7890%s", c, str);
	printf("\n");
	printf("return of original printf: %ld\n", i);
	printf("17 means text is 5, and %%, str is 11 \n");

	p = &c;
	printf("-------------------------------------------------\n");
	printf("here is test for char *p\n");
	printf("p is address of c, and text is 12345%%p\n");
	printf("-------------------------------------------------\n");
	i = ft_printf("12345%p", p);
	printf("\n");
	printf("return ft_printf: %ld\n", i);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	i = printf("12345%p", p);
	printf("\n");
	printf("return of original printf: %ld\n", i);
	printf("17 means text is 5, and %%, str is 11 \n");

	d = 1234567;
	printf("-------------------------------------------------\n");
	printf("here is test for char *d\n");
	printf("d is number 42, and text is 12345%%d\n");
	printf("-------------------------------------------------\n");
	i = ft_printf("12345%d", d);
	printf("\n");
	printf("return ft_printf: %ld\n", i);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	i = printf("12345%d", d);
	printf("\n");
	printf("return of original printf: %ld\n", i);
	printf("17 means text is 5, and %%, str is 11 \n");

	x = 123456;
	printf("-------------------------------------------------\n");
	printf("here is test for undigned int x\n");
	printf("x is number 255, and text is 12345%%x\n");
	printf("-------------------------------------------------\n");
	i = ft_printf("12345%x", x);
	printf("\n");
	printf("return ft_printf: %ld\n", i);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	i = printf("12345%x", x);
	printf("\n");
	printf("return of original printf: %ld\n", i);

	X = 2147483647;
	printf("-------------------------------------------------\n");
	printf("here is test for undigned int X\n");
	printf("x is number 2147483647, and text is 12345%%X\n");
	printf("-------------------------------------------------\n");
	i = ft_printf("12345%X", X);
	printf("\n");
	printf("return ft_printf: %ld\n", i);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	i = printf("12345%X", X);
	printf("\n");
	printf("return of original printf: %ld\n", i);
	return (0);
}