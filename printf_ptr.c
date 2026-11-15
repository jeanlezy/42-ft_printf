/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanbarr <jeanbarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:55:48 by jeanbarr          #+#    #+#             */
/*   Updated: 2026/11/14 11:58:20 by jeanbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (printf_str("(nil)"));
	count = printf_str("0x");
	count += printf_hex((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
