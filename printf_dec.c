/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanbarr <jeanbarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:40:06 by jeanbarr          #+#    #+#             */
/*   Updated: 2026/11/14 12:14:31 by jeanbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_dec(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += printf_dec(nb / 10);
	count += printf_char((nb % 10) + '0');
	return (count);
}
