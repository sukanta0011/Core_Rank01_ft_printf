#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef unsigned int	t_uint;
typedef unsigned int	t_bool;

typedef struct	s_fmt
{
	int		num;
	t_uint	unum;
	char	c;
	char	*str;
	void	*ptr;
}				t_fmt;

typedef struct	s_str
{
	char	*str;
	t_uint	len;
	t_uint	size;
}				t_str;

typedef struct	s_fmt_specifier
{
	t_str	flag_dtls;
	char	specifier;
	t_bool	flags;
	t_bool	dot;
	t_uint	width;
	t_uint	precision;
	t_str	var;
}				t_fmt_specifier;

void	ft_putnbr_base(int nbr, char *base, unsigned int base_len);
void	ft_putptr_base(unsigned long nbr, char *base, unsigned int base_len);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void 	parse_specifier(t_fmt_specifier *fmt_spcfr, char *fmt, t_uint *i);
void	parse_specifier_value(t_fmt_specifier *fmt_spcfr, va_list ap);
void	print_nbr(int num, char fmt);
void	print_ptr(void *ptr, char fmt);
void	append_char(t_str *str_dtls, char c);
char	*ft_strdup(char *src, char *dst);
void	print_str(t_fmt_specifier *fmt_spcfr, char *str);
int		char_in_str(char c, char *str);
void	ft_putstr_len(char *str, t_uint len);

#endif