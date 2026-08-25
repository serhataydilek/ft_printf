/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 05:15:21 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/25 05:52:57 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_format(const char *format, va_list *args);
int	ft_putchar_printf(char c);
int	ft_conversion(char type, va_list *args);
int	ft_conversion_hex(char type, va_list *args);

int	ft_printf_putstr(char *s);
int	ft_printf_putnbr(int nb);
int	ft_printf_putunbr(unsigned int nb);

int	ft_hex(unsigned long nb);
int	ft_hex_up(unsigned long nb);
int	ft_putptr(void *ptr);

#endif