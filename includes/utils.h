#ifndef UTILS_H
# define UTILS_H

typedef struct s_fmt
{
	int				i;
	unsigned int	u;
	char			c;
	char			*str;
	void			*ptr;
}				t_fmt;

void	ft_putnbr_base(int nbr, char *base, unsigned int base_len);

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);

#endif