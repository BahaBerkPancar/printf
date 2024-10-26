#ifndef FT_PRINTF_C
# define FT_PRINTF_C


#include <stdarg.h>
#include <stdio.h>

int ft_check_type(char c, va_list arg);
int ft_printf(const char *str, ...);
int ft_putnbr(int n);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_printf_unsigned(unsigned int a);
int ft_hexa(unsigned int i, char c);

#endif