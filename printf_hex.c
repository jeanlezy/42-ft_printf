/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanbarr <jeanbarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:53:16 by jeanbarr          #+#    #+#             */
/*   Updated: 2026/11/13 15:05:12 by jeanbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// Conversões %x e %X
int	printf_hex(unsigned long nb, char *base)
{
	int count;

	count = 0;
	if (nb >= 16)
		count += (printf_hex(nb / 16,  base));
}
