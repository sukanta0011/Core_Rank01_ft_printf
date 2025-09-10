#include "ft_printf.h"

void	use_left_padding(t_fmt_specifier *fmt_spcfr, char pad)
{
	t_uint	len;
	t_uint	width;
	t_uint	precision;
	t_uint	i;

	len = fmt_spcfr->var.len;
	width = fmt_spcfr->width;
	precision = fmt_spcfr->precision;
	i = 0;
	if (fmt_spcfr->dot && precision < len)
		len = precision;
	while (i  < (width - len))
	{
		ft_putchar(pad);
		i++;
	}
	ft_putstr_len(fmt_spcfr->var.str, len);
}

void	use_right_padding(t_fmt_specifier *fmt_spcfr, char pad)
{
	t_uint	len;
	t_uint	width;
	t_uint	precision;
	t_uint	i;

	len = fmt_spcfr->var.len;
	width = fmt_spcfr->width;
	precision = fmt_spcfr->precision;
	i = 0;
	if (fmt_spcfr->dot && precision < len)
		len = precision;
	ft_putstr_len(fmt_spcfr->var.str, len);
	while (i  < (width - len))
	{
		ft_putchar(pad);
		i++;
	}
}

void print_str(t_fmt_specifier *fmt_spcfr, char *str)
{
	t_uint i;

	i = 0;
	while (str[i])
	{
		append_char(&(fmt_spcfr->var), str[i]);
		i++;
	}
	if (fmt_spcfr->flags)
	{
		if (char_in_str('-', fmt_spcfr->flag_dtls.str))
			use_right_padding(fmt_spcfr, ' ');
	} 
	else
		use_left_padding(fmt_spcfr, ' ');
}
