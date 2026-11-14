/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanbarr <jeanbarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:41:27 by jeanbarr          #+#    #+#             */
/*   Updated: 2026/11/13 12:11:05 by jeanbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...); // Principal
int	printf_char(int c); // Conversao %c - OK
int	printf_dec(unsigned int nb); // Conversão %u
int	printf_hex(unsigned long nb, char *base); // Conversões %x e %X
int	printf_int(int nb); //Conversão d% ou %i
int	printf_ptr(void *ptr); //Conversão %p
int	printf_str(char *str); //Conversão %s

#endif