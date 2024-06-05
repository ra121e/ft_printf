/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:32:30 by athonda           #+#    #+#             */
/*   Updated: 2024/06/05 19:50:21 by athonda          ###   ########.fr       */
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

int	ft_printpointer(char * p)
{
	int	i;

	i = 0;
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
		i = ft_printpointer(va_arg(ap, char *));
	}
	else if (c == 'd' || c == 'i')
	{
		i = ft_printnbr(va_arg(ap, int));
	}
	else if (c == 'x')
	{
		i = ft_printhexa(va_arg(ap, unsigned int));
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
/*
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
*/
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
	return (0);
}