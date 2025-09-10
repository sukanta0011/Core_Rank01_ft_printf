#include "ft_printf.h"

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{	
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putstr_len(char *str, t_uint len)
{	
	t_uint i;

	i = 0;
	while(str[i] && i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{	
	write(1, &c, 1);
}

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

int	char_in_str(char c, char *str)
{
	t_uint	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);	
}