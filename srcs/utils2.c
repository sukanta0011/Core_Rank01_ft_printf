/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:06:41 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 10:06:41 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *src, char *dst)
{
	t_uint	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}

void	append_char(t_str *str_dtls, char c)
{
	char	*temp;

	if (!str_dtls->str)
		str_dtls->str = malloc(str_dtls->size);
	else if (str_dtls->len + 1 > str_dtls->size)
	{
		temp = malloc(str_dtls->size);
		temp = ft_strdup(str_dtls->str, temp);
		free(str_dtls->str);
		str_dtls->size *= 2;
		str_dtls->str = malloc(str_dtls->size);
		str_dtls->str = ft_strdup(temp, str_dtls->str);
		free(temp);
	}
	str_dtls->str[str_dtls->len++] = c;
	str_dtls->str[str_dtls->len] = '\0';
}

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
	while (i < (width - len))
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
	while (i < (width - len))
	{
		ft_putchar(pad);
		i++;
	}
}
