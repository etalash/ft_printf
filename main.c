/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:14:07 by stalash           #+#    #+#             */
/*   Updated: 2024/03/27 15:14:07 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	if ((write(1, &c, 1)) == -1)
		return (-1);
	return (1);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int	ft_putstr(char const *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
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

int	ft_putnbr(long long nb)
{
	int		count;

	count = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
	{
		int ret = ft_putnbr(nb / 10); // Recursive call for printing digits
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar(nb % 10 + '0') == -1)
		return (-1);
	return (count + 1);
}

// int	ft_putnbr(long long nb, int base, int upercase)
// {
// 	int		count;
// 	char	*symbol;

// 	count = 0;
// 	if (upercase == 1)
// 		symbol = "0123456789ABCDEF";
// 	else
// 		symbol = "0123456789abcdef";
// 	if (nb < 0 && base == 10)
// 	{
// 		// count += ft_putchar('-');
// 		if (ft_putchar('-') == -1)
// 			return (-1);
// 		nb = -nb;
// 		count++;
// 	}
// 	return (count += print_hexa(nb, base, symbol));
// 	// if (nb < (unsigned long long)base)
// 	// 	return (ft_putchar(symbol[nb]));
// 	// count += ft_putnbr(nb / base, base, upercase);
// 	// if (count == -1)
// 	// 	return (-1);
// 	// return (count += ft_putnbr(nb % base, base, upercase));
// }

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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (ch == s[i])
			break ;
		s++;
	}
	if (ch == s[i])
		return ((char *)(s + i));
	else
		return (0);
}

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

// int main()
// {
// 	ft_printf("&&*%d\n", 14);
// 	printf("&&*%d", 14);
// }
