/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:15:13 by stalash           #+#    #+#             */
/*   Updated: 2024/03/25 18:36:49 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	convert_format(char spicifier, va_list ap)
{
	int	count;

	count = 0;
	if (spicifier == '%')
		count += ft_putchar('%');
	else if (spicifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (spicifier == 's')
	{
		char	*str;

		str = va_arg(ap, char *);
		if (str)
			count += ft_putstr(str);
		else
			count += ft_putstr("(null)");
	}
	else if (spicifier == 'd' || spicifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10, 0);
	else if (spicifier == 'u')
		count += print_digit((unsigned long)(va_arg(ap, unsigned int)), 10, 0);
	else if (spicifier == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (spicifier == 'x')
		count += print_digit(va_arg(ap, unsigned long), 16, 0);
	else if (spicifier == 'X')
		count += print_digit(va_arg(ap, unsigned long), 16, 1);
	else
		count += write(1, &spicifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += convert_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
