/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:49:54 by stalash           #+#    #+#             */
/*   Updated: 2024/03/25 18:33:40 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_digit(unsigned long long nb, int base, int upercase)
{
	int		count;
	char	*symbol;

	count = 0;
	if (upercase)
		symbol = "0123456789ABCDF";
	else
		symbol = "0123456789abcdef";
	if ((long long)nb < 0 && base == 10)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	if (nb < (unsigned long)base)
		return (ft_putchar(symbol[nb]));
	count += print_digit(nb / base, base, upercase);
	if (count == -1)
		return (-1);
	return (count + print_digit(nb % base, base, upercase));
}

int	print_hexa(unsigned long long val, int base, char *str)
{
	int	count;

	count = 0;
	if (val >= (unsigned long long)base)
		count += print_hexa((val / base), base, str);
	if (write(1, &str[val % base], 1) == -1)
		return (-1);
	return (count + 1);
}

int	print_pointer(void *ptr)
{
	char				*symbol;
	unsigned long long	int_val;
	int					count;

	symbol = "0123456789abcdef";
	int_val = (unsigned long long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	if (count == -1)
		return (-1);
	if (int_val == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (count + 1);
	}
	else
		return (count += print_hexa(int_val, 16, symbol));
}

// int	print_hexa(unsigned long long val, int base, char *str)
// {
// 	int	count;

// 	count = 0;
// 	if (val >= (unsigned long long) base)
// 	{
// 		count += print_hexa((val / base), 16, str);
// 	}
// 	count += print_hexa(str[val % base], 16, str);
// 	return (count);
// }
