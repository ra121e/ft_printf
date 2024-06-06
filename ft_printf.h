/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:02:58 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 14:49:21 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printpointer(unsigned long long addrs);
int	ft_printnbr(int nb);
int	ft_printunbr(unsigned int nb);
int	ft_printhexa(unsigned int nb, char specifier);
int	ft_printfilter(char c, va_list ap);

#endif // FT_PRINTF_H