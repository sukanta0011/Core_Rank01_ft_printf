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

void	ft_putnbr_base(t_fmt_specifier *fmt_spcfr, int nbr,
		char *base, t_uint base_len)
{
	int		mod;
	t_uint	new_nb;

	if (nbr < 0)
	{
		new_nb = -nbr;
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
	t_uint	sign_len;
	char	*sign_str;

	sign_len = 0;
	sign_str = "";
	if (num < 0)
	{
		sign_len = 1;
		sign_str = "-";
	}
	if (fmt == 'd' || fmt == 'i')
		ft_putnbr_base(fmt_spcfr, num, "0123456789", ft_strlen("0123456789"));
	if (fmt_spcfr->flags)
	{
		if (char_in_str('+', fmt_spcfr->flag_dtls.str))
		{	
			sign_len = 1;
			sign_str = "+";
		}
		if (char_in_str(' ', fmt_spcfr->flag_dtls.str))
		{	
			sign_len = 1;
			sign_str = " ";
		}
		if (char_in_str('-', fmt_spcfr->flag_dtls.str))
			use_num_right_padding(fmt_spcfr, ' ', sign_len, sign_str);
		else if (char_in_str('0', fmt_spcfr->flag_dtls.str))
			use_num_left_padding(fmt_spcfr, '0', sign_len, sign_str);
		else if (char_in_str('+', fmt_spcfr->flag_dtls.str)
			|| char_in_str(' ', fmt_spcfr->flag_dtls.str))
			use_num_left_padding(fmt_spcfr, ' ', sign_len, sign_str);
	}
	else
		use_num_left_padding(fmt_spcfr, ' ', sign_len, sign_str);
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

void	print_unum_with_paddings(t_fmt_specifier *fmt_spcfr,
			int hx_len, char *hx_str)
{
	if (fmt_spcfr->flags)
	{
		if (char_in_str('#', fmt_spcfr->flag_dtls.str))
		{
			hx_len = 2;
			if (fmt_spcfr->specifier == 'x')
				hx_str = "0x";
			if (fmt_spcfr->specifier == 'X')
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
	print_unum_with_paddings(fmt_spcfr, hx_len, hx_str);
}
