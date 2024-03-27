/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:17 by fharifen          #+#    #+#             */
/*   Updated: 2024/03/27 16:37:36 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_next(char format, va_list args, int *count)
{
	if (format == 'c') 
		print_char(va_arg(args, int), count);
	else if (format == 's')
		print_str(va_arg(args, char *), count);
	else if (format == 'd' || format == 'i') 
		print_nbr(va_arg(args, int), format, count);
	else if (format == 'u') 
		print_nbr(va_arg(args, unsigned int), format, count);
	else if (format == 'x') 
		print_hex(va_arg(args, unsigned int), format, count);
	else if (format == 'X') 
		print_hex(va_arg(args, unsigned int), format, count);
	else if (format == 'p') 
		print_ptr(va_arg(args, void *), count);
	else if (format == '%') 
		print_char(format, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			check_next(format[++i], args, &count);
		else
			print_char(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
