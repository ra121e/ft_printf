/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:56:17 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 00:18:56 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

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