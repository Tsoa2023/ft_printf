/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:17 by fharifen          #+#    #+#             */
/*   Updated: 2024/03/27 16:37:37 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	print_str(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*count = *count + 6;
		return ;
	}
	while (str[i])
	{
		print_char(str[i], count);
		i++;
	}
}

void	print_nbr(long nbr, char format, int *count)
{
	if (format == 'u')
		nbr = (unsigned int)nbr;
	if (nbr < 0)
	{
		nbr = -nbr;
		print_char('-', count);
	}
	if (nbr > 9)
	{
		print_nbr((nbr / 10), format, count);
		print_char((nbr % 10) + '0', count);
	}
	else
		print_char(nbr + '0', count);
}

void	print_hex(unsigned long nbr, char format, int *count)
{
	char *str;

	str = "0123456789abcdef";
	if (format == 'X')
		str = "0123456789ABCDEF";
	if (nbr > 15)
	{
		print_hex((nbr / 16), format, count);
		print_char(str[nbr % 16], count);
	}
	else
		print_char(str[nbr], count);
}

void	print_ptr(void *n, int *count)
{
	unsigned long ptr;

	ptr = (unsigned long)n;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	print_str("0x", count);
	print_hex(ptr, 'x', count);
}
