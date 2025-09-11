/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:55:22 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 09:55:22 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	use_num_left_padding(t_fmt_specifier *fmt_spcfr, char pad,
		t_uint hx_len, char *hx_str)
{
	t_uint	len;
	t_uint	width;
	t_uint	precision;
	t_uint	i;

	len = fmt_spcfr->var.len;
	width = fmt_spcfr->width;
	precision = fmt_spcfr->precision;
	i = 0;
	if (fmt_spcfr->dot && precision > len && width >= precision)
	{
		while (i < (width - precision - hx_len))
		{
			ft_putchar(pad);
			i++;
		}
		ft_putstr(hx_str);
		while (i < width - len - hx_len)
		{
			ft_putchar('0');
			i++;
		}
	}
	else if (fmt_spcfr->dot && precision > len && width < precision)
	{
		ft_putstr(hx_str);
		while (i < (precision - len))
		{
			ft_putchar('0');
			i++;
		}
	}
	else
	{
		while ((int)i < (int)(width - len - hx_len))
		{
			ft_putchar(pad);
			i++;
		}
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
	t_uint	i;

	len = fmt_spcfr->var.len;
	width = fmt_spcfr->width;
	precision = fmt_spcfr->precision;
	i = 0;
	if (fmt_spcfr->dot && precision < len)
		len = precision;
	if (fmt_spcfr->dot && precision > len && width >= precision)
	{
		ft_putstr(hx_str);
		while (i < precision - len)
		{
			ft_putchar('0');
			i++;
		}
		ft_putstr(fmt_spcfr->var.str);
		i = 0;
		while (i < (width - precision - hx_len))
		{
			ft_putchar(pad);
			i++;
		}
	}
	else if (fmt_spcfr->dot && precision > len && width < precision)
		use_num_left_padding(fmt_spcfr, '0', hx_len, hx_str);
	else
	{
		ft_putstr(hx_str);
		ft_putstr_len(fmt_spcfr->var.str, len);
		while ((int)i < (int)(width - len - hx_len))
		{
			ft_putchar(pad);
			i++;
		}
	}
}

void	ft_putnbr_base(t_fmt_specifier *fmt_spcfr, int nbr,
		char *base, t_uint base_len)
{
	int		mod;
	t_uint	new_nb;

	if (nbr < 0)
	{
		new_nb = -nbr;
		append_char(&(fmt_spcfr->var), '-');
	}
	else
		new_nb = nbr;
	if (new_nb > base_len - 1)
		ft_putnbr_base(fmt_spcfr, new_nb / base_len, base, base_len);
	mod = new_nb % base_len;
	append_char(&(fmt_spcfr->var), base[mod]);
}

void	print_nbr(t_fmt_specifier *fmt_spcfr, int num, char fmt)
{
	char	*dec_base;
	t_uint	hx_len;
	char	*hx_str;

	hx_len = 0;
	hx_str = "";
	dec_base = "0123456789";
	if (fmt == 'd' || fmt == 'i')
		ft_putnbr_base(fmt_spcfr, num, dec_base, ft_strlen(dec_base));
	if (fmt_spcfr->flags)
	{
		if (char_in_str('-', fmt_spcfr->flag_dtls.str))
			use_num_right_padding(fmt_spcfr, ' ', hx_len, hx_str);
		else if (char_in_str('0', fmt_spcfr->flag_dtls.str))
			use_num_left_padding(fmt_spcfr, '0', hx_len, hx_str);
	}
	else
		use_num_left_padding(fmt_spcfr, ' ', hx_len, hx_str);
}

void	ft_putunbr_base(t_fmt_specifier *fmt_spcfr, t_uint nbr,
		char *base, t_uint base_len)
{
	int		mod;

	if (nbr > base_len - 1)
		ft_putunbr_base(fmt_spcfr, nbr / base_len, base, base_len);
	mod = nbr % base_len;
	append_char(&(fmt_spcfr->var), base[mod]);
}

void	print_unbr(t_fmt_specifier *fmt_spcfr, t_uint num, char fmt)
{
	char	*cap_hex_base;
	char	*hex_base;
	char	*dec_base;
	t_uint	hx_len;
	char	*hx_str;

	hx_len = 0;
	hx_str = "";
	cap_hex_base = "0123456789ABCDEF";
	hex_base = "0123456789abcdef";
	dec_base = "0123456789";
	if (fmt == 'u')
		ft_putunbr_base(fmt_spcfr, num, dec_base, ft_strlen(dec_base));
	if (fmt == 'x')
		ft_putunbr_base(fmt_spcfr, num, hex_base, ft_strlen(hex_base));
	if (fmt == 'X')
		ft_putunbr_base(fmt_spcfr, num, cap_hex_base, ft_strlen(cap_hex_base));
	if (fmt_spcfr->flags)
	{
		if (char_in_str('#', fmt_spcfr->flag_dtls.str))
		{
			hx_len = 2;
			if (fmt == 'x')
				hx_str = "0x";
			if (fmt == 'X')
				hx_str = "0X";
		}
		if (char_in_str('-', fmt_spcfr->flag_dtls.str))
			use_num_right_padding(fmt_spcfr, ' ', hx_len, hx_str);
		else if (char_in_str('0', fmt_spcfr->flag_dtls.str))
			use_num_left_padding(fmt_spcfr, '0', hx_len, hx_str);
		else if (char_in_str('#', fmt_spcfr->flag_dtls.str))
			use_num_left_padding(fmt_spcfr, ' ', hx_len, hx_str);
	}
	else
		use_num_left_padding(fmt_spcfr, ' ', hx_len, hx_str);
}
