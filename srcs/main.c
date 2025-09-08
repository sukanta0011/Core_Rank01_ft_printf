#include <stdarg.h>
#include <stdio.h>

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	char	*s;

	va_start(ap, fmt);
	while (*fmt)
	{
		s = va_arg(ap, char *);
		printf("%c, string: %s\n", *fmt, s);
		*fmt++;
	}
	va_end(ap);
}

int main(void)
{
	ft_printf("1234", "world", "How", "are", "you");
	return (0);
}