#include "ft_printf.h"


void	parse_specifier(t_fmt_specifier *fmt_spcfr, char *fmt, t_uint *i)
{
	char	*flags;
	
	flags = "+-#0 ";
	while(char_in_str(fmt[*i], flags) && fmt[*i] != '\0')
	{
		append_char(&(fmt_spcfr->flag_dtls), fmt[*i]);
		fmt_spcfr->flags = 1;
		(*i)++;
	}
	while((fmt[*i] >= '0' && fmt[*i] <= '9') && fmt[*i] != '\0')
	{
		fmt_spcfr->width = fmt_spcfr->width * 10 + fmt[*i] - '0';
		(*i)++;
	}
	if (fmt[*i] == '.')
	{
		(*i)++;
		fmt_spcfr->dot = 1;
		while((fmt[*i] >= '0' && fmt[*i] <= '9') && fmt[*i] != '\0')
		{
			fmt_spcfr->precision = fmt_spcfr->precision * 10 + fmt[*i] - '0';
			(*i)++;
		}
	}
	fmt_spcfr->specifier = fmt[*i];
}

void	parse_specifier_value(t_fmt_specifier *fmt_spcfr, va_list ap)
{
	t_fmt	var;

	if (fmt_spcfr->specifier == 's')
	{
		var.str = va_arg(ap, char *);
		print_str(fmt_spcfr, var.str);
	}
	if (fmt_spcfr->specifier == 'd' || fmt_spcfr->specifier == 'i' || fmt_spcfr->specifier == 'u'
		|| fmt_spcfr->specifier == 'x' || fmt_spcfr->specifier == 'X')
	{
		var.num = va_arg(ap, int);
		print_nbr(var.num, fmt_spcfr->specifier);
	}
	if (fmt_spcfr->specifier == 'c')
	{
		var.c = va_arg(ap, int);
		ft_putchar(var.c);
	}
	if (fmt_spcfr->specifier == 'p')
	{
		var.ptr = va_arg(ap, void *);
		print_ptr(var.ptr, fmt_spcfr->specifier);
	}
}
