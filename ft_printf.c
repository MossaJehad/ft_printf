/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:50:13 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/01/21 13:59:09 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char format_char, va_list args)
{
	if (format_char == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format_char == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format_char == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (format_char == 'd' || format_char == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format_char == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format_char == 'x' || format_char == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format_char));
	else if (format_char == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_format(format[i], args);
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
