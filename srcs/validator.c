/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:01:05 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 21:01:05 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	validate_str_flags(char *flags, char fmt, t_bool dot)
{
	if (fmt == 'c' || fmt == 's')
	{
		if (char_in_str('#', flags) || char_in_str(' ', flags)
			|| char_in_str('+', flags))
			return (0);
	}
	if (fmt == 'c' && dot)
		return (0);	
	return (1);
}

int	validate_num_flags(char *flags, char fmt, t_bool dot)
{
	if (fmt == 'd' || fmt == 'i')
	{
		if (char_in_str('#', flags))
			return (0);
		if (char_in_str('0', flags) && (char_in_str('-', flags)
			|| dot))
			return (0);
	}
	return (1);
}

int	validate_ptr_flags(char *flags, char fmt, t_bool dot)
{
	if (fmt == 'p')
	{
		if (char_in_str('#', flags) || char_in_str(' ', flags)
			|| char_in_str('+', flags) || char_in_str('0', flags) || dot)
			return (0);
	}
	return (1);
}

int	validate_unum_flags(char *flags, char fmt, t_bool dot)
{
	if (fmt == 'u' || fmt == 'x' || fmt == 'X')
	{
		if (char_in_str('+', flags) || char_in_str(' ', flags))
			return (0);
		if (char_in_str('0', flags) && dot)
			return (0);
	}
	return (1);
}

int	validate_flags_comb(t_fmt_specifier *fmt_spcfr)
{
	char	fmt;
	char	*flags;
	t_bool	dot;

	fmt = fmt_spcfr->specifier;
	flags = fmt_spcfr->flag_dtls.str;
	dot = fmt_spcfr->dot;
	if (fmt == 'c' || fmt == 's')
	{
		if (fmt_spcfr->flag_dtls.str)
			return (validate_str_flags(flags, fmt, dot));
	}
	if (fmt == 'p')
	{
		if (fmt_spcfr->flag_dtls.str)
			return (validate_str_flags(flags, fmt, dot));
	}
	if (fmt == 'u' || fmt == 'x' || fmt == 'X')
	{
		if (fmt_spcfr->flag_dtls.str)
			return (validate_str_flags(flags, fmt, dot));
	}
	if (fmt == 'd' || fmt == 'i')
		return (validate_num_flags(flags, fmt, dot));
	return (1);
}