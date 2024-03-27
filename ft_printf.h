/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:32:01 by fharifen          #+#    #+#             */
/*   Updated: 2024/03/27 16:37:41 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...);
void	print_char(char c, int *count);
void	print_str(char *str, int *count);
void	print_nbr(long nbr, char format, int *count);
void	print_hex(unsigned long nbr, char format, int *count);
void	print_ptr(void *n, int *count);

#endif
