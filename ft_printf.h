/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanbarr <jeanbarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:41:27 by jeanbarr          #+#    #+#             */
/*   Updated: 2026/11/14 11:55:32 by jeanbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	printf_char(int c);
int	printf_dec(unsigned int nb);
int	printf_hex(unsigned long nb, char *base);
int	printf_int(int nb);
int	printf_ptr(void *ptr);
int	printf_str(char *str);

#endif