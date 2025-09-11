/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:55:13 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 09:55:13 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_specifier(t_fmt_specifier *fmt_spcfr, char *fmt, t_uint *i)
{
	char	*flags;

	flags = "+-#0 ";
	while (char_in_str(fmt[*i], flags) && fmt[*i] != '\0')
	{
		append_char(&(fmt_spcfr->flag_dtls), fmt[*i]);
		fmt_spcfr->flags = 1;
		(*i)++;
	}
	while ((fmt[*i] >= '0' && fmt[*i] <= '9') && fmt[*i] != '\0')
	{
		fmt_spcfr->width = fmt_spcfr->width * 10 + fmt[*i] - '0';
		(*i)++;
	}
	if (fmt[*i] == '.')
	{
		(*i)++;
		fmt_spcfr->dot = 1;
		while ((fmt[*i] >= '0' && fmt[*i] <= '9') && fmt[*i] != '\0')
		{
			fmt_spcfr->precision = fmt_spcfr->precision * 10 + fmt[*i] - '0';
			(*i)++;
		}
	}
	fmt_spcfr->specifier = fmt[*i];
}

void	parse_num(t_fmt_specifier *fmt_spcfr, t_fmt *var, char fmt, va_list ap)
{
	if (fmt == 'd' || fmt == 'i')
	{
		var->num = va_arg(ap, int);
		print_nbr(fmt_spcfr, var->num, fmt_spcfr->specifier);
	}
	if (fmt == 'u' || fmt == 'x' || fmt == 'X')
	{
		var->unum = va_arg(ap, t_uint);
		print_unbr(fmt_spcfr, var->unum, fmt_spcfr->specifier);
	}
}

void	parse_str(t_fmt_specifier *fmt_spcfr, t_fmt *var, char fmt, va_list ap)
{
	if (fmt == 's')
	{
		var->str = va_arg(ap, char *);
		print_str(fmt_spcfr, var->str);
	}
	if (fmt == 'c')
	{
		var->num = va_arg(ap, int);
		print_char(fmt_spcfr, var->num);
	}
}

void	parse_specifier_value(t_fmt_specifier *fmt_spcfr, va_list ap)
{
	t_fmt	var;
	char	fmt;

	fmt = fmt_spcfr->specifier;
	if (fmt == 's' || fmt == 'c')
		parse_str(fmt_spcfr, &var, fmt, ap);
	if (fmt == 'd' || fmt == 'i'
		|| fmt == 'u' || fmt == 'x' || fmt == 'X')
		parse_num(fmt_spcfr, &var, fmt, ap);
	if (fmt == 'p')
	{
		var.ptr = va_arg(ap, void *);
		print_ptr(fmt_spcfr, var.ptr);
	}
}
