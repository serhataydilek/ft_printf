/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 04:55:55 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/25 05:21:46 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_conversion(char type, va_list *args)
{
	if (type == 'c')
		return (ft_putchar_printf(va_arg(*args, int)));
	if (type == 's')
		return (ft_printf_putstr(va_arg(*args, char *)));
	if (type == 'd' || type == 'i')
		return (ft_printf_putnbr(va_arg(*args, int)));
	if (type == 'u')
		return (ft_printf_putunbr(va_arg(*args, unsigned int)));
	return (ft_conversion_hex(type, args));
}

int	ft_conversion_hex(char type, va_list *args)
{
	if (type == 'x')
		return (ft_hex(va_arg(*args, unsigned int)));
	if (type == 'X')
		return (ft_hex_up(va_arg(*args, unsigned int)));
	if (type == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (type == '%')
		return (ft_putchar_printf('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	result = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			result += ft_conversion(format[i + 1], &args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			result++;
		}
		i++;
	}
	va_end(args);
	return (result);
}
