/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanbarr <jeanbarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:54:26 by jeanbarr          #+#    #+#             */
/*   Updated: 2026/11/14 12:15:13 by jeanbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(int nb)
{
	long	num;
	int		count;

	num = nb;
	count = 0;
	if (num < 0)
	{
		count += printf_char('-');
		num = -num;
	}
	if (num > 9)
		count += printf_int(num / 10);
	count += printf_char((num % 10) + '0');
	return (count);
}
