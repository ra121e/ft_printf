/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:56:17 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 11:59:31 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

/*
#define TEST_CASE(name, format, ...) \
    do { \
        int ret_printf = printf(format, __VA_ARGS__); \
        int ret_ft_printf = ft_printf(format, __VA_ARGS__); \
        printf("Test case: %s\n", name); \
        printf("printf output: "); \
        printf(format, __VA_ARGS__); \
        printf("\nft_printf output: "); \
        ft_printf(format, __VA_ARGS__); \
        printf("\n"); \
        printf("printf return: %d, ft_printf return: %d\n", ret_printf, ret_ft_printf); \
        if (ret_printf != ret_ft_printf) { \
            printf("Return values do not match!\n"); \
        } \
        printf("\n"); \
    } while (0)
*/

void	t_c(void)
{
	char	c;
	size_t	len;
    int ret_printf, ret_ft_printf;

	// 文字 ('%c')
    printf("\n===== Testing %%c =====\n");
    printf("printf output: ");
    ret_printf = printf("%c", 'A');
	printf("\n");
    printf("\nft_printf output: ");
	printf("\n");
    ret_ft_printf = ft_printf("%c", 'A');
    printf("\nprintf return: %d, ft_printf return: %d\n", ret_printf, ret_ft_printf);
    if (ret_printf != ret_ft_printf) {
        printf("Return values do not match!\n");
    }

    printf("\nTest case: Null character\n");
    printf("printf output: ");
    ret_printf = printf("%c", '\0');
    printf("\nft_printf output: ");
    ret_ft_printf = ft_printf("%c", '\0');
    printf("\n");
    printf("printf return: %d, ft_printf return: %d\n", ret_printf, ret_ft_printf);
    if (ret_printf != ret_ft_printf) {
        printf("Return values do not match!\n");
    }

    printf("\nTest case: Non-printable character\n");
    printf("printf output: ");
    ret_printf = printf("%c", '\x07');
    printf("\nft_printf output: ");
    ret_ft_printf = ft_printf("%c", '\x07');
    printf("\n");
    printf("printf return: %d, ft_printf return: %d\n", ret_printf, ret_ft_printf);
    if (ret_printf != ret_ft_printf) {
        printf("Return values do not match!\n");
    }

	c = 'a';
	printf("-------------------------------------------------\n");
	printf("here is test for char c\n");
	printf("c is 'a', and text is 12345%%c\n");
	printf("-------------------------------------------------\n");
	len = ft_printf("12345%c", c);
	printf("\n");
	printf("return ft_printf: %ld\n", len);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	len = printf("12345%c", c);
	printf("\n");
	printf("return of original printf: %ld\n", len);
	printf("the number of return means length of text 5 letters and %% and c\n");

}

void	t_s(void)
{
	//char	*str;
	int ret_printf, ret_ft_printf;
	size_t	len;
    char *str = "Hello, World!";
    char *null_str = NULL;
    printf("\n===== Testing %%s =====\n");
    printf("printf output: ");
    ret_printf = printf("%s", str);
    printf("\nft_printf output: ");
    ret_ft_printf = ft_printf("%s", str);
    printf("\nprintf return: %d, ft_printf return: %d\n", ret_printf, ret_ft_printf);
    if (ret_printf != ret_ft_printf) {
        printf("Return values do not match!\n");
    }
	    printf("printf output: ");
    ret_printf = printf("%s", null_str);
    printf("\nft_printf output: ");
    ret_ft_printf = ft_printf("%s", null_str);
    printf("\nprintf return: %d, ft_printf return: %d\n", ret_printf, ret_ft_printf);
    if (ret_printf != ret_ft_printf) {
        printf("Return values do not match!\n");
    }
	str = "42Singapore";
	printf("-------------------------------------------------\n");
	printf("here is test for char *s\n");
	printf("str is 42Singapore, and text is 12345%%s\n");
	printf("-------------------------------------------------\n");
	len = ft_printf("12345%s", str);
	printf("\n");
	printf("return ft_printf: %ld\n", len);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	len = printf("12345%s", str);
	printf("\n");
	printf("return of original printf: %ld\n", len);
	printf("17 means text is 5, and %%, str is 11 \n");
}

void	t_p(void)
{
	char	c;
	size_t	len;
	char	*p;

	c = 'a';
	p = &c;
	printf("-------------------------------------------------\n");
	printf("here is test for char *p\n");
	printf("p is address of c, and text is 12345%%p\n");
	printf("-------------------------------------------------\n");
	len = ft_printf("12345%p", p);
	printf("\n");
	printf("return ft_printf: %ld\n", len);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	len = printf("12345%p", p);
	printf("\n");
	printf("return of original printf: %ld\n", len);
	printf("17 means text is 5, and %%, str is 11 \n");

}

void	t_d(void)
{
	int	d;
	size_t	len;

	d = 1234567;
	printf("-------------------------------------------------\n");
	printf("here is test for char *d\n");
	printf("d is number 42, and text is 12345%%d\n");
	printf("-------------------------------------------------\n");
	len = ft_printf("12345%d", d);
	printf("\n");
	printf("return ft_printf: %ld\n", len);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	len = printf("12345%d", d);
	printf("\n");
	printf("return of original printf: %ld\n", len);
	printf("17 means text is 5, and %%, str is 11 \n");
}

void	t_i(void)
{

	int	i;
	size_t	len;

	i = 1234567;
	printf("-------------------------------------------------\n");
	printf("here is test for decimal i\n");
	printf("d is number 42, and text is 12345%%i\n");
	printf("-------------------------------------------------\n");
	len = ft_printf("12345%i", i);
	printf("\n");
	printf("return ft_printf: %ld\n", len);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	len = printf("12345%i", i);
	printf("\n");
	printf("return of original printf: %ld\n", len);
	printf("17 means text is 5, and %%, str is 11 \n");
}

void	t_u(void)
{

	unsigned int	u;
	size_t	len;

	u = 1234567;
	printf("-------------------------------------------------\n");
	printf("here is test for unsigned int u\n");
	printf("d is number 42, and text is 12345%%u\n");
	printf("-------------------------------------------------\n");
	len = ft_printf("12345%u", u);
	printf("\n");
	printf("return ft_printf: %ld\n", len);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	len = printf("12345%u", u);
	printf("\n");
	printf("return of original printf: %ld\n", len);
	printf("17 means text is 5, and %%, str is 11 \n");
}
void	t_x(void)
{
	unsigned int	x;
	size_t	len;

	x = 123456;
	printf("-------------------------------------------------\n");
	printf("here is test for undigned int x\n");
	printf("x is number 255, and text is 12345%%x\n");
	printf("-------------------------------------------------\n");
	len = ft_printf("12345%x", x);
	printf("\n");
	printf("return ft_printf: %ld\n", len);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	len = printf("12345%x", x);
	printf("\n");
	printf("return of original printf: %ld\n", len);

}

void	t_X(void)
{
	unsigned int	X;
	size_t	len;

	X = 2147483647;
	printf("-------------------------------------------------\n");
	printf("here is test for undigned int X\n");
	printf("x is number 2147483647, and text is 12345%%X\n");
	printf("-------------------------------------------------\n");
	len = ft_printf("12345%X", X);
	printf("\n");
	printf("return ft_printf: %ld\n", len);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	len = printf("12345%X", X);
	printf("\n");
	printf("return of original printf: %ld\n", len);
}

void	t_mix()
{
	size_t	len;
	char	c;
	char	*str;

	c = 'a';
	str = "42Singapore";
	printf("-------------------------------------------------\n");
	printf("here is mix test of char c and char *s\n");
	printf("c is 'a', and text is 12345%%c890%%s\n");
	printf("str is 42Singapore, and text is 12345%%c890%%s\n");
	printf("-------------------------------------------------\n");
	len = ft_printf("12345%c7890%s", c, str);
	printf("\n");
	printf("return ft_printf: %ld\n", len);

	printf("------------------------------------\n");
	printf("here is original printf\n");
	len = printf("12345%c7890%s", c, str);
	printf("\n");
	printf("return of original printf: %ld\n", len);
	printf("17 means text is 5, and %%, str is 11 \n");
}
int	main(void)
{

//	t_c();
	t_s();
//	t_p();
//	t_d();
//	t_i();
//	t_u();
//	t_x();
//	t_X();
//	t_mix();

	return (0);
}