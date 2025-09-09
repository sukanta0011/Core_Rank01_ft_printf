#include <stdarg.h>
#include <stdio.h>
#include "utils.h"

void	print_nbr(int num, char fmt)
{
	char	*cap_hex_base;
	char	*hex_base;
	char	*dec_base;

	cap_hex_base = "0123456789ABCDEF";
	hex_base = "0123456789abcdef";
	dec_base = "0123456789";
	if (fmt == 'd' || fmt == 'i' || fmt == 'u')
		ft_putnbr_base(num, dec_base, ft_strlen(dec_base));
	if (fmt == 'x')
		ft_putnbr_base(num, hex_base, ft_strlen(hex_base));
	if (fmt == 'X')
		ft_putnbr_base(num, cap_hex_base, ft_strlen(cap_hex_base));
}

void	print_ptr(void *ptr, char fmt)
{
	char				*hex_base;
	// unsigned int		ptr_size;
	unsigned long		num;

	// ptr_size = sizeof(ptr);
	num = (unsigned long)ptr;
	hex_base = "0123456789abcdef";
	if (fmt == 'p')
	{
		ft_putstr("0x");
		ft_putptr_base(num, hex_base, ft_strlen(hex_base));
	}
}

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_fmt	var;
	// char	*flags;

	// flags = "-+.0# ";
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 's')
			{
				var.str = va_arg(ap, char *);
				ft_putstr(var.str);
			}
			if (*fmt == 'd' || *fmt == 'i' || *fmt == 'u'
					|| *fmt == 'x' || *fmt == 'X')
			{
				var.i = va_arg(ap, int);
				print_nbr(var.i, *fmt);
			}
			if (*fmt == 'c')
			{
				var.c = va_arg(ap, int);
				ft_putchar(var.c);
			}
			if (*fmt == 'p')
			{
				var.ptr = va_arg(ap, void *);
				print_ptr(var.ptr, *fmt);
			}
		}
		else 
			ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	int a = 160;
	// int	*b = &a;
	printf("----------ft_printf--------------\n");
	ft_printf("%% %s %u %c %p %x\n", "world", a, 'a', &a, a);
	printf("-----------printf---------------\n");
	printf("%% %.2s %+10i %c %p %#.10x\n", "world", a, 'a', &a, a);
	// ft_putstr("Hello world");
	return (0);
}