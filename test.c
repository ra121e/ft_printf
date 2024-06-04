/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:24:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/04 20:21:37 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	char	c;
	char	*str;
	char			*p;
	int				d;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
	int	i;
	va_list	ap;

	va_start(ap, format);

	printf("format argumant 1 inside: %s\n", format);
	c = va_arg(ap, int);
	printf("arg inside ft_printf:c -> %c\n", c);
	str = va_arg(ap, char *);
	printf("arg inside ft_printf:str -> %s\n", str);
	p = va_arg(ap, char *);
	printf("arg inside ft_printf:pointer -> %p\n", p);
	d = va_arg(ap, int);
	printf("arg inside ft_printf:decimal -> %d\n", d);
	d = va_arg(ap, int);
	printf("arg inside ft_printf:decimal i -> %i\n", d);
	u = va_arg(ap, unsigned int);
	printf("arg inside ft_printf:unsigned int  -> %u\n", u);
	x = va_arg(ap, int);
	printf("arg inside ft_printf:hexadeciaml by x -> %x\n", x);
	X = va_arg(ap, int);
	printf("arg inside ft_printf:hexadecimal by X -> %X\n", X);
	printf("\n");


	printf("roun2 no initialize format argumant 1 inside: %s\n", format);
	c = va_arg(ap, int);
	printf("arg inside ft_printf:c -> %c\n", c);
	str = va_arg(ap, char *);
	printf("arg inside ft_printf:str -> %s\n", str);
	p = va_arg(ap, char *);
	printf("arg inside ft_printf:pointer -> %p\n", p);
	d = va_arg(ap, int);
	printf("arg inside ft_printf:decimal -> %d\n", d);
	d = va_arg(ap, int);
	printf("arg inside ft_printf:decimal i -> %i\n", d);
	u = va_arg(ap, unsigned int);
	printf("arg inside ft_printf:unsigned int  -> %u\n", u);
	x = va_arg(ap, int);
	printf("arg inside ft_printf:hexadeciaml by x -> %x\n", x);
	X = va_arg(ap, int);
	printf("arg inside ft_printf:hexadecimal by X -> %X\n", X);
	printf("\n");

	va_start(ap, format);

	printf("round 3 with initialize format argumant 1 inside: %s\n", format);
	c = va_arg(ap, int);
	printf("arg inside ft_printf:c -> %c\n", c);
	str = va_arg(ap, char *);
	printf("arg inside ft_printf:str -> %s\n", str);
	p = va_arg(ap, char *);
	printf("arg inside ft_printf:pointer -> %p\n", p);
	d = va_arg(ap, int);
	printf("arg inside ft_printf:decimal -> %d\n", d);
	d = va_arg(ap, int);
	printf("arg inside ft_printf:decimal i -> %i\n", d);
	u = va_arg(ap, unsigned int);
	printf("arg inside ft_printf:unsigned int  -> %u\n", u);
	x = va_arg(ap, int);
	printf("arg inside ft_printf:hexadeciaml by x -> %x\n", x);
	X = va_arg(ap, int);
	printf("arg inside ft_printf:hexadecimal by X -> %X\n", X);
	return (i);
}

int	main(void)
{
	char			c;
	char			str[] = "42singapore";
	char			*p;
	int				d;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;

	c = 'a';
	p = &c;
	d = 12345;
	u = 2147483648;
	x = 255;
	X = 255;
	printf("%c\n", c);
	printf("%s\n", str);
	printf("%p\n", p);
	printf("%d\n", d);
	printf("%i\n", d);
	printf("%u\n", u);
	printf("%x\n", x);
	printf("%X\n", X);
	printf("%c %s %p %d %i %u %x %X \n", c, str, p, d, d, u, x, X);
	ft_printf("send total variable: %c %s %p %d %i %u %x %X \n", c, str, p, d, d, u, x, X);
	return (0);
}