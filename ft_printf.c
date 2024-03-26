/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:17 by fharifen          #+#    #+#             */
/*   Updated: 2024/03/26 21:33:31 by fharifen         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_next(char format, va_list args, int count)
{
	if (format == 'c') 
		count += print_char(va_arg(args, int));
	else if (format == 's')
		count += print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i') 
		count += print_nbr(va_arg(args, int), format);
	else if (format == 'u') 
		count += print_nbr(va_arg(args, int), format);
	else if (format == 'x') 
		print_hex(va_arg(args, int), format);
	else if (format == 'X') 
		count += print_hex(va_arg(args, int), format);
	else if (format == 'p') 
		count += print_ptr(va_arg(args, void *));
	else if (format == '%') 
		count += print_char(format);

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
			count += check_next(format[++i], args, count);
		else
			count += print_char(format[i]);
		i++;
	}
	return (count);
}
#include <stdio.h>
int	main(void)
{
	char *ptr;
	int count1;
	int count2;

	ptr = "test";
	 count1 = ft_printf("\nChar: %c\nString: %s\nInteger: %d\nhex: %x\nHEX: %X\nunsigned: %u\npointer: %p\n%%", 'Z', "Hello", 42, -20, -20, -255, &ptr); 
	 count2 = printf("\nChar: %c\nString: %s\nInteger: %d\nhex: %x\nHEX: %X\nunsigned: %u\npointer: %p\n%%", 'Z', "Hello", 42, -20, -20, -255, &ptr); 
	printf("\ncount1 ft_printf = %d\n", count1);
	printf("\ncount2 printf = %d\n", count2);

	return (0);
}
