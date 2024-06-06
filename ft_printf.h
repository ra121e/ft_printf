/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:02:58 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 23:43:16 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_printfilter(char c, va_list ap);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void *p);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_puthexa(unsigned long long nb, int hexatype);

#endif // FT_PRINTF_H