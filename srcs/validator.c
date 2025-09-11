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

int	validate_str_flags(char *fmt_spcfr)
{
	
}

int valide_flags_comb(t_fmt_specifier *fmt_spcfr)
{
	char fmt;
	char *flags;

	fmt = fmt_spcfr->specifier;
	flags = fmt_spcfr->flag_dtls.str;
	if (fmt == 'c' || fmt == 's')
		validate_str_flags(flags);
}