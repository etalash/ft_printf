/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:40:00 by stalash           #+#    #+#             */
/*   Updated: 2024/03/27 12:40:00 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += (ft_putchar((va_arg(args, int))));
	else if (format == 's')
		count += (ft_putstr((va_arg(args, char *))));
	else if (format == 'd' || format == 'i')
		count += (ft_putnbr((va_arg(args, int)), 10, 0));
	else if (format == 'x')
		count += (ft_putnbr(va_arg(args, unsigned int), 16, 0));
	else if (format == 'X')
		count += (ft_putnbr(va_arg(args, unsigned int), 16, 1));
	else if (format == 'p')
		count += (print_pointer(va_arg(args, void *)));
	else if (format == 'u')
		count += (ft_putnbr(va_arg(args, unsigned int), 10, 0));
	else if (format == '%')
		count += (ft_putchar('%'));
	return (count);
}

// int	ft_printf(const char *str, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		length;

// 	i = 0;
// 	length = 0;
// 	va_start(args, str);
// 	while (*(str + i))
// 	{
// 		if ((*(str + i) == '%') && (ft_strchr("cspdiuxX%", *(str + i + 1))))
// 		{
// 			length += ft_format(args, *(str + i + 1));
// 			i++;
// 		}
// 		else
// 			length += ft_putchar(*(str + i));
// 		i++;
// 	}
// 	va_end(args);
// 	return (length);
// }
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if ((*(str + i) == '%') && (ft_strchr("cspdiuxX%", *(str + i + 1))))
		{
			int ret = ft_format(args, *(str + i + 1));
			if (ret == -1)
				return (-1); // Return -1 immediately if an error occurs
			length += ret;
			i++;
		}
		else
		{
			int ret = ft_putchar(*(str + i));
			if (ret == -1)
				return (-1); // Return -1 immediately if an error occurs
			length += ret;
		}
		i++;
	}
	va_end(args);
	return (length);
}
