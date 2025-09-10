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
	return dst;
}

void	flags_append(t_flags *flag_dtls, char c)
{
	char	*temp;

	if (!flag_dtls->flags)
	{
		flag_dtls->cap = 2;
		flag_dtls->flags = malloc(flag_dtls->cap);
		flag_dtls->len = 0;
		flag_dtls->flags[0] = '\0';
	}
	if (flag_dtls->len + 1 > flag_dtls->cap)
	{
		temp = malloc(flag_dtls->cap);
		temp = ft_strdup(flag_dtls->flags, temp);
		free(flag_dtls->flags);
		flag_dtls->cap *= 2;
		flag_dtls->flags = malloc(flag_dtls->cap);
		flag_dtls->flags = ft_strdup(temp, flag_dtls->flags);
		free(temp);
	}
	flag_dtls->flags[flag_dtls->len++] = c;
	flag_dtls->flags[flag_dtls->len] = '\0';
}

int	is_in_flags(char c)
{
	char	*flags;
	t_uint	i;
	
	flags = "+-#0 ";
	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);	
}


int parse_specifier(t_fmt_specifier *fmt_spcfr, char *fmt, t_uint *i)
{
	while(is_in_flags(fmt[*i]) && fmt[*i] != '\0')
	{
		flags_append(&(fmt_spcfr->flag_dtls), fmt[*i]);
		(*i)++;
	}
	while((fmt[*i] >= '0' && fmt[*i] <= '9') && fmt[*i] != '\0')
	{
		fmt_spcfr->width = fmt_spcfr->width * 10 + fmt[*i] - '0';
		(*i)++;
	}
	if (fmt[*i] == '.')
	{
		(*i)++;
		while((fmt[*i] >= '0' && fmt[*i] <= '9') && fmt[*i] != '\0')
		{
			fmt_spcfr->precision = fmt_spcfr->precision * 10 + fmt[*i] - '0';
			(*i)++;
		}
	}
	fmt_spcfr->specifier = fmt[*i];
	return (0);
}
