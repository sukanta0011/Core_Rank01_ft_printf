#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef unsigned int	t_uint;

typedef struct s_fmt
{
	int		i;
	t_uint	u;
	char	c;
	char	*str;
	void	*ptr;
}				t_fmt;

typedef struct	s_flags
{
	char	*flags;
	t_uint	len;
	t_uint	cap;
}				t_flags;

typedef struct	s_fmt_specifier
{
	t_flags	flag_dtls;
	char	specifier;
	t_uint	width;
	t_uint	precision;
	t_uint	var_len;
	t_fmt	var_val;
}				t_fmt_specifier;

void	ft_putnbr_base(int nbr, char *base, t_uint base_len);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putptr_base(unsigned long int nbr, char *base, t_uint base_len);
int 	parse_specifier(t_fmt_specifier *fmt_spcfr, char *fmt, t_uint *i);

#endif