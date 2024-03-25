
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
	count += (print_digit(nb / base, base, upercase));
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

int	ft_putchar(char c)
{
	if ((write(1, &c, 1)) == -1)
		return (-1);
	return 1;
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (ft_putchar(*str++) == -1)
			return (-1);
		i++;
	}
	return (i);
}

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
		count += print_digit((long)(va_arg(ap, unsigned int)), 10, 0);
	else if (spicifier == 'p')
		count += print_pointer((void *)(va_arg(ap, void *)));
	else if (spicifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned long)), 16, 0);
	else if (spicifier == 'X')
		count += print_digit((long)(va_arg(ap, unsigned long)), 16, 1);
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
