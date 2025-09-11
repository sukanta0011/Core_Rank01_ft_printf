/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_adds1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:55:19 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 09:55:19 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_base(t_fmt_specifier *fmt_spcfr, t_ullint nbr,
		char *base, t_uint base_len)
{
	t_ullint	mod;
	t_ullint	new_nb;

	new_nb = nbr;
	if (new_nb > base_len - 1)
		ft_putptr_base(fmt_spcfr, new_nb / base_len, base, base_len);
	mod = new_nb % base_len;
	append_char(&(fmt_spcfr->var), base[mod]);
}

void	print_ptr(t_fmt_specifier *fmt_spcfr, void *ptr)
{
	char		*hex_base;
	t_ullint	num;
	t_uint		hx_len;
	char		*hx_str;

	num = (unsigned long)ptr;
	hex_base = "0123456789abcdef";
	hx_len = 2;
	hx_str = "0x";
	ft_putptr_base(fmt_spcfr, num, hex_base, ft_strlen(hex_base));
	if (fmt_spcfr->flags)
	{
		if (char_in_str('-', fmt_spcfr->flag_dtls.str))
			use_num_right_padding(fmt_spcfr, ' ', hx_len, hx_str);
	}
	else
		use_num_left_padding(fmt_spcfr, ' ', hx_len, hx_str);
}
