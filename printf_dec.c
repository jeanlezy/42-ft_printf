/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanbarr <jeanbarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:40:06 by jeanbarr          #+#    #+#             */
/*   Updated: 2026/11/13 15:02:03 by jeanbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	printf_dec(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += printf_dec(nb / 10);
	ft_putchar((nb % 10) + '0');
	count++;
	return (count);
}
