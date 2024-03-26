/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:32:01 by fharifen          #+#    #+#             */
/*   Updated: 2024/03/26 21:07:58 by fharifen         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_str(char *str);
int print_nbr(long nbr, char format);
int print_hex(long n, char format);
int	print_ptr(void *n);

#endif
