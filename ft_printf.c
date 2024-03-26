/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:17 by fharifen          #+#    #+#             */
/*   Updated: 2024/03/26 12:09:12 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_next(char format, va_list args, int count)
{
	if (format == 'c') 
		print_char(va_arg(args, int));
	else if (format == 's')
		print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i') 
		print_nbr(va_arg(args, int), format);
	else if (format == 'u') 
		print_nbr(va_arg(args, int), format);
	else if (format == 'x') 
		print_hex(va_arg(args, int), format);
	else if (format == 'X') 
		print_hex(va_arg(args, int), format);
	else if (format == 'p') 
		print_hex(va_arg(args, int), format);

	return (count);
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
			count = check_next(format[++i], args, count);
		else
			count = print_char(format[i]);
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main(void)
{
	char *ptr;

	ptr = "test";
	/* ft_printf("\nChar: %c\nString: %s\nInteger: %d\nhex: %x\nHEX: %X\nunsigned: %u\npointer: %p\n", 'Z', "Hello", 42, -20, -20, -255, &ptr); */
	printf("\nChar: %c\nString: %s\nInteger: %d\nhex: %x\nHEX: %X\nunsigned: %u\npointer: %p\n", 'Z', "Hello", 42, -20, -20, -255, &ptr);

	return (0);
}
