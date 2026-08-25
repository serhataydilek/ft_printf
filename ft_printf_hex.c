/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 04:56:51 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/25 05:21:54 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_up(unsigned long nb)
{
	char		digit;
	int			count;
	const char	*hex;

	hex = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
	{
		count += ft_hex_up(nb / 16);
	}
	digit = hex[nb % 16];
	write(1, &digit, 1);
	count++;
	return (count);
}

int	ft_hex(unsigned long nb)
{
	char		digit;
	int			count;
	const char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
	{
		count += ft_hex(nb / 16);
	}
	digit = hex[nb % 16];
	write(1, &digit, 1);
	count++;
	return (count);
}
