/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_paddings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:22:57 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 16:22:57 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	use_num_left_padding(t_fmt_specifier *fmt_spcfr, char pad,
		t_uint hx_len, char *hx_str)
{
	t_uint	len;
	t_uint	width;
	t_uint	precision;

	len = fmt_spcfr->var.len;
	width = fmt_spcfr->width;
	precision = fmt_spcfr->precision;
	if (fmt_spcfr->dot && precision > len && width >= precision)
	{
		print_padding_char(pad, (width - precision - hx_len));
		ft_putstr(hx_str);
		print_padding_char(pad, (precision - len));
	}
	else if (fmt_spcfr->dot && precision > len && width < precision)
	{
		ft_putstr(hx_str);
		print_padding_char('0', (precision - len));
	}
	else
	{
		print_padding_char(pad, (width - len - hx_len));
		ft_putstr(hx_str);
	}
	ft_putstr(fmt_spcfr->var.str);
}

void	use_num_right_padding(t_fmt_specifier *fmt_spcfr, char pad,
		t_uint hx_len, char *hx_str)
{
	t_uint	len;
	t_uint	width;
	t_uint	precision;

	len = fmt_spcfr->var.len;
	width = fmt_spcfr->width;
	precision = fmt_spcfr->precision;
	if (fmt_spcfr->dot && precision < len)
		len = precision;
	if (fmt_spcfr->dot && precision > len && width >= precision)
	{
		ft_putstr(hx_str);
		print_padding_char('0', (precision - len));
		ft_putstr(fmt_spcfr->var.str);
		print_padding_char(pad, (width - precision - hx_len));
	}
	else if (fmt_spcfr->dot && precision > len && width < precision)
		use_num_left_padding(fmt_spcfr, '0', hx_len, hx_str);
	else
	{
		ft_putstr(hx_str);
		ft_putstr_len(fmt_spcfr->var.str, len);
		print_padding_char(pad, (width - len - hx_len));
	}
}
