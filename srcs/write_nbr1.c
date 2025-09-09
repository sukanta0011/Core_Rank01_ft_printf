#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base, unsigned int base_len)
{
	int				mod;
	unsigned int	new_nb;

	if (nbr < 0)
	{
		new_nb = -nbr;
		write (1, "-", 1);
	}
	else
		new_nb = nbr;
	if (new_nb > base_len - 1)
		ft_putnbr_base(new_nb / base_len, base, base_len);
	mod = new_nb % base_len;
	write (1, &base[mod], 1);
}
