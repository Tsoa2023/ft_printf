/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:24:17 by fharifen          #+#    #+#             */
/*   Updated: 2024/03/26 12:06:55 by fharifen         ###   ########.fr       */
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
		print_char(str[i]);
		count++;
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
		print_char('-');
	}
	if (nbr > 9)
	{
		print_nbr((nbr / 10), format);
		print_char((nbr % 10) + '0');
	}
	else
		print_char(nbr + '0');
	return (count);
}

int print_hex(long n, char format)
{
	int count;
	char *str;
	unsigned int	nbr;

	nbr = (unsigned int)n;
	if (format == 'p')
	{
		print_str("0x");
	}
	if (format == 'x')
		str = "0123456789abcdef";
	else if (format == 'X')
		str = "0123456789ABCDEF";
	count = 0;
	if (nbr > 16)
	{
		print_hex((nbr / 16), format);
		print_char(str[nbr % 16]);
	}
	else
		print_char(str[nbr]);
	return (count);
}
