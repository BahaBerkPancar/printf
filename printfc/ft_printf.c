#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	int i;
	int count;
	va_list a;

	va_start(a, str);
	i = 0;
	while(str[i])
	{
		if(str[i] != '%')
		{
			ft_putchar(str[i]);
			count++;
		}
		if(str[i] == '%')
		{
			i += 1;
			while(str[i] == ' ' && str[i])
				i++;			
				count = ft_check_type(str[i], a);

		}
		i++;
	}
	return (count);
}
int main()
{
	printf("%d", ft_printf("%cs%cs%c", 'c', 'b', 'a'));
}

