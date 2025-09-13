/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:55:06 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 09:55:06 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef unsigned int		t_uint;
typedef unsigned int		t_bool;
typedef unsigned long long	t_ullint;

typedef struct s_fmt
{
	int		num;
	t_uint	unum;
	char	*str;
	void	*ptr;
}				t_fmt;

typedef struct s_str
{
	char	*str;
	t_uint	len;
	t_uint	size;
}				t_str;

typedef struct s_fmt_specifier
{
	t_str	flag_dtls;
	char	specifier;
	t_bool	flags;
	t_bool	dot;
	t_uint	width;
	t_uint	precision;
	t_str	var;
}				t_fmt_specifier;

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	parse_specifier(t_fmt_specifier *fmt_spcfr, char *fmt, t_uint *i);
void	parse_specifier_value(t_fmt_specifier *fmt_spcfr, va_list ap);
int		char_in_str(char c, char *str);
void	ft_putstr_len(char *str, t_uint len);
int		validate_str_flags(char *flags, char fmt, t_bool dot);
int 	validate_flags_comb(t_fmt_specifier *fmt_spcfr);

// =========== write_add ================ //
void	ft_putptr_base(t_fmt_specifier *fmt_spcfr, t_ullint nbr,
			char *base, t_uint base_len);
void	print_ptr(t_fmt_specifier *fmt_spcfr, void *ptr);

// =========== write_nbr ================ //
void	ft_putnbr_base(t_fmt_specifier *fmt_spcfr, int nbr,
			char *base, t_uint base_len);
void	print_nbr(t_fmt_specifier *fmt_spcfr, int num, char fmt);
void	ft_putunbr_base(t_fmt_specifier *fmt_spcfr, t_uint nbr,
			char *base, t_uint base_len);
void	print_unbr(t_fmt_specifier *fmt_spcfr, t_uint num, char fmt);
void	print_unum_with_paddings(t_fmt_specifier *fmt_spcfr, int hx_len,
			char *hx_str);

// =========== num_paddings ================ //
void	use_num_left_padding(t_fmt_specifier *fmt_spcfr, char pad,
			t_uint hx_len, char *hx_str);
void	extend_num_left_padding(t_fmt_specifier *fmt_spcfr, char pad,
			t_uint str_len, char *str);
void	use_num_right_padding(t_fmt_specifier *fmt_spcfr, char pad,
			t_uint hx_len, char *hx_str);

// =========== write_str ================ //
void	use_str_left_padding(t_fmt_specifier *fmt_spcfr, char pad);
void	use_str_right_padding(t_fmt_specifier *fmt_spcfr, char pad);
void	print_str(t_fmt_specifier *fmt_spcfr, char *str);
void	print_char(t_fmt_specifier *fmt_spcfr, int c);
void	print_str_with_paddings(t_fmt_specifier *fmt_spcfr);

// =========== utils2 ================ //
char	*ft_strcpy(char *src, char *dst);
void	append_char(t_str *str_dtls, char c);
void	print_padding_char(char pad, t_uint len);

#endif