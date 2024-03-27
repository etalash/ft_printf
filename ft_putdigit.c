/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:46:03 by stalash           #+#    #+#             */
/*   Updated: 2024/03/27 13:46:03 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// int	print_hexa(unsigned long long val, int base, char *str)
// {
// 	int	count;

// 	count = 0;
// 	if (val >= (unsigned long long)base)
// 		count += print_hexa((val / base), base, str);
// 	if (write(1, &str[val % base], 1) == -1)
// 		return (-1);
// 	return (count + 1);
// }

int	print_hexa(unsigned long long val, int base, char *str)
{
	int	count;

	count = 0;
	if (val >= (unsigned long long)base)
		count += print_hexa((val / base), base, str);
	if (write(1, &str[val % base], 1) == -1)
		return (-1); // Return -1 if write fails
	return (count + 1);
}

int	ft_putnbr(long long nb, int base, int upercase)
{
	int		count;
	char	*symbol;

	count = 0;
	if (upercase == 1)
		symbol = "0123456789ABCDEF";
	else
		symbol = "0123456789abcdef";
	if (nb < 0 && base == 10)
	{
		// count += ft_putchar('-');
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	return (count += print_hexa(nb, base, symbol));
	// if (nb < (unsigned long long)base)
	// 	return (ft_putchar(symbol[nb]));
	// count += ft_putnbr(nb / base, base, upercase);
	// if (count == -1)
	// 	return (-1);
	// return (count += ft_putnbr(nb % base, base, upercase));
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
