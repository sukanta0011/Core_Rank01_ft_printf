#include <unistd.h>

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

void	ft_putchar(char c)
{	
	write(1, &c, 1);
}