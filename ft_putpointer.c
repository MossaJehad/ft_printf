/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:46:48 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/01/20 15:36:46 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long long num, const char format);
static int	hex_len_p(unsigned long long num);
static void	ft_put_hex_p(unsigned long long num, const char format);

int	ft_putpointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_putptr((unsigned long long)ptr, 'x');
	return (count);
}

static int	hex_len_p(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex_p(unsigned long long num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex_p(num / 16, format);
		ft_put_hex_p(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

static int	ft_putptr(unsigned long long num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	ft_put_hex_p(num, format);
	return (hex_len_p(num));
}
