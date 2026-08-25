/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saydilek <saydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 04:55:54 by saydilek          #+#    #+#             */
/*   Updated: 2026/08/25 05:42:04 by saydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_printf_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf_putnbr(int nb)
{
	char	digit;
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
	{
		count += ft_printf_putnbr(nb / 10);
	}
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}

int	ft_printf_putunbr(unsigned int nb)
{
	char	digit;
	int		count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_printf_putunbr(nb / 10);
	}
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}

int	ft_putptr(void *s)
{
	int				count;
	unsigned long	address;

	if (!s)
		return (ft_printf_putstr("(nil)"));
	count = 2;
	write(1, "0x", 2);
	address = (unsigned long)s;
	count += ft_hex(address);
	return (count);
}
