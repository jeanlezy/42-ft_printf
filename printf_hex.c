/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanbarr <jeanbarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:53:16 by jeanbarr          #+#    #+#             */
/*   Updated: 2026/11/14 12:16:01 by jeanbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hex(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += printf_hex(nb / 16, base);
	count += printf_char(base[nb % 16]);
	return (count);
}
