#include <unistd.h>
#include "ft_printf.h"


int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int ft_putstr(char *str)
{
	int count;

	count = 0;
	int i;
	if(!str)
		return (0);
	i = 0;
	while(str[i])
		count += ft_putchar(str[i++]);
	return(count);
}
int ft_putnbr(int n)
{
	int i;

	i = 0;
	if(n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		i += ft_putchar('-');
	}
	if(n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	if(n < 10)
	{
		i += ft_putchar(n + 48);
	}
	return (i);
}
int ft_printf_unsigned(unsigned int a)
{
	int i;

	i = 0;
	if(a < 10 && a > 0)
		i += ft_putchar(a + 48);
	if (a > 9)
	{
		i += ft_printf_unsigned(a / 10);
		i += ft_printf_unsigned(a % 10);
	}
	return (i);
}
int ft_hexa(unsigned int i, char c)
{
	char *base;
	int count;

	count = 0;
	if (c == 'x')
	{
		base = "0123456789abcdef";
		if (i >= 16)
			ft_hexa(i / 16, c);
		count += ft_putchar(base[i % 16]);
	}
	if (c == 'X')
	{
		base = "0123456789ABCDEF";
		if (i >= 16)
			ft_hexa(i / 16, c);
		count += ft_putchar(base[i % 16]);
	}
	return (count);
}