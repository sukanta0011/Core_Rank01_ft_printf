#include "ft_printf.h"

t_fmt_specifier *initialize_mem(t_fmt_specifier *fmt_spcfr)
{
	fmt_spcfr = malloc(sizeof(t_fmt_specifier));
	fmt_spcfr->flag_dtls.str = NULL;
	fmt_spcfr->flag_dtls.len = 0;
	fmt_spcfr->flag_dtls.size = 2;
	fmt_spcfr->flags = 0;
	fmt_spcfr->dot = 0;
	fmt_spcfr->width = 0;
	fmt_spcfr->precision = 0;
	fmt_spcfr->specifier = 0;
	fmt_spcfr->var.str = NULL;
	fmt_spcfr->var.len = 0;
	fmt_spcfr->var.size = 2;
	return (fmt_spcfr);
}

void free_memory(t_fmt_specifier *fmt_spcfr)
{
	if (fmt_spcfr->flag_dtls.str)
		free(fmt_spcfr->flag_dtls.str);
	if (fmt_spcfr->var.str)
		free(fmt_spcfr->var.str);
	free(fmt_spcfr);
}

int ft_printf(const char *fmt, ...)
{
	va_list			ap;
	t_fmt_specifier	*fmt_spcfr;
	t_uint			i;

	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			fmt_spcfr = initialize_mem(fmt_spcfr);
			parse_specifier(fmt_spcfr, (char *)fmt, &i);
			parse_specifier_value(fmt_spcfr, ap);
			free_memory(fmt_spcfr);
		}
		else 
			ft_putchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (0);
}


int main(void)
{
	// int a = 160;
	// int	*b = &a;
	printf("----------ft_printf--------------\n");
	ft_printf("%-10.1s, %10.1s\n", "Hello", "World");
	printf("-----------printf---------------\n");
	printf("%-10.1s, %10.1s\n", "Hello", "World");
	return (0);
}