/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanbarr <jeanbarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:32:05 by jeanbarr          #+#    #+#             */
/*   Updated: 2026/11/15 11:39:00 by jeanbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handler(char c, va_list *args)
{
	if (c == 'c')
		return (printf_char(va_arg(*args, int)));
	else if (c == 'u')
		return (printf_dec(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (printf_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (printf_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'd' || c == 'i')
		return (printf_int(va_arg(*args, int)));
	else if (c == 'p')
		return (printf_ptr(va_arg(*args, void *)));
	else if (c == 's')
		return (printf_str(va_arg(*args, char *)));
	else if (c == '%')
		return (printf_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += handler(format[i + 1], &args);
			i += 2;
		}
		else
		{
			count += printf_char(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
