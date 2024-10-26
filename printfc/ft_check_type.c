#include "ft_printf.h"

int ft_check_type(char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		count += ft_printf_unsigned(va_arg(arg, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	else if(c == 'x' || c == 'X')
		count += ft_hexa(va_arg(arg, int), c);
	return (count);
}