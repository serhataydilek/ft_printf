/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 04:55:55 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/25 05:17:29 by saydilek         ###   ########.fr       */
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
	i = -1;
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

#include <limits.h>

int	main(void)
{
	int	result;
	int	x;

	x = 42;

	ft_printf("\n===== EMPTY =====\n");
	result = ft_printf("");
	ft_printf("\nreturn = %d | expected = 0\n", result);

	ft_printf("\n===== NORMAL =====\n");
	result = ft_printf("abc");
	ft_printf("\nreturn = %d | expected = 3\n", result);

	ft_printf("\n===== CHAR =====\n");
	result = ft_printf("%c", 'A');
	ft_printf("\nreturn = %d | expected = 1\n", result);

	ft_printf("\n===== STRING =====\n");
	result = ft_printf("%s", "serhat");
	ft_printf("\nreturn = %d | expected = 6\n", result);

	result = ft_printf("[%s]", "");
	ft_printf("\nreturn = %d | expected = 2\n", result);

	ft_printf("\n===== D / I =====\n");
	result = ft_printf("%d", 0);
	ft_printf("\nreturn = %d | expected = 1\n", result);

	result = ft_printf("%d", 42);
	ft_printf("\nreturn = %d | expected = 2\n", result);

	result = ft_printf("%d", -42);
	ft_printf("\nreturn = %d | expected = 3\n", result);

	result = ft_printf("%d", INT_MAX);
	ft_printf("\nreturn = %d | expected = 10\n", result);

	result = ft_printf("%d", INT_MIN);
	ft_printf("\nreturn = %d | expected = 11\n", result);

	result = ft_printf("%i", -12345);
	ft_printf("\nreturn = %d | expected = 6\n", result);

	ft_printf("\n===== UNSIGNED =====\n");
	result = ft_printf("%u", 0U);
	ft_printf("\nreturn = %d | expected = 1\n", result);

	result = ft_printf("%u", UINT_MAX);
	ft_printf("\nreturn = %d | expected = 10\n", result);

	ft_printf("\n===== HEX LOWER =====\n");
	result = ft_printf("%x", 0U);
	ft_printf("\nreturn = %d | expected = 1\n", result);

	result = ft_printf("%x", 10U);
	ft_printf("\nreturn = %d | expected = 1\n", result);

	result = ft_printf("%x", 16U);
	ft_printf("\nreturn = %d | expected = 2\n", result);

	result = ft_printf("%x", 255U);
	ft_printf("\nreturn = %d | expected = 2\n", result);

	result = ft_printf("%x", UINT_MAX);
	ft_printf("\nreturn = %d | expected = 8\n", result);

	ft_printf("\n===== HEX UPPER =====\n");
	result = ft_printf("%X", 10U);
	ft_printf("\nreturn = %d | expected = 1\n", result);

	result = ft_printf("%X", 255U);
	ft_printf("\nreturn = %d | expected = 2\n", result);

	result = ft_printf("%X", UINT_MAX);
	ft_printf("\nreturn = %d | expected = 8\n", result);

	ft_printf("\n===== PERCENT =====\n");
	result = ft_printf("%%%%");
	ft_printf("\nreturn = %d | expected = 2\n", result);

	ft_printf("\n===== CONSECUTIVE =====\n");
	result = ft_printf("%d%d%d", 1, 2, 3);
	ft_printf("\nreturn = %d | expected = 3\n", result);

	result = ft_printf("%c%s%x", '!', "test", 255U);
	ft_printf("\nreturn = %d | expected = 7\n", result);

	ft_printf("\n===== BETWEEN TEXT =====\n");
	result = ft_printf("A%cB%sC%dD", 'Z', "ok", 42);
	ft_printf("\nreturn = %d | expected = 9\n", result);

	ft_printf("\n===== POINTER =====\n");
	result = ft_printf("%p\n", (void *)&x);
	ft_printf("pointer return = %d\n", result);

	ft_printf("\n===== MIXED =====\n");
	result = ft_printf(
			"A:%c S:%s D:%d I:%i U:%u x:%x X:%X %%\n",
			'Z', "ok", -12, 34, 42U, 255U, 255U);
	ft_printf("return = %d | expected = 37\n", result);

	return (0);
}