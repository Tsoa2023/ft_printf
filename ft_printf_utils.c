/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:17 by fharifen          #+#    #+#             */
/*   Updated: 2024/03/26 21:33:07 by fharifen         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count += print_char(str[i]);
		i++;
	}
	return (count);
}

int print_nbr(long nbr, char format)
{
	int count;

	count = 0;
	if (format == 'u')
		nbr = (unsigned int)nbr;
	if (nbr < 0)
	{
		nbr = -nbr;
		count += print_char('-');
	}
	if (nbr > 9)
	{
		print_nbr((nbr / 10), format);
		count += print_char((nbr % 10) + '0');
	}
	else
		count += print_char(nbr + '0');
	return (count);
}

int print_hex(long n, char format)
{
	static int count;
	char *str;
	unsigned int	nbr;

	nbr = (unsigned int)n;
	count = 0;
	str = "0123456789abcdef";
	if (format == 'X')
		str = "0123456789ABCDEF";
	if (nbr > 16)
	{
		print_hex((nbr / 16), format);
		count += print_char(str[nbr % 16]);
	}
	else
		count += print_char(str[nbr]);
	return (count);
}

int	print_ptr(void *n)
{
	int	count;
	unsigned long int	ptr;

	ptr = (unsigned long int)n;
	if (!ptr)
		return (0);
	count = 0;
	print_str("0x");
	count += 2;
	count += print_hex(ptr, 'x');
	return (count);
}
