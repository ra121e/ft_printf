/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:02:58 by athonda           #+#    #+#             */
/*   Updated: 2024/06/06 00:17:50 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printpointer(unsigned long long addrs);
int	ft_printnbr(int	nb);
int	ft_printhexa(unsigned int nb, char specifier);
int	ft_filter(char c, va_list ap);

#endif // LIBFTPRINTF_H