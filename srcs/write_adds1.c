#include <unistd.h>

void	ft_putptr_base(unsigned long nbr, char *base, unsigned int base_len)
{
	unsigned long		mod;
	unsigned long		new_nb;

	new_nb = nbr;
	if (new_nb > base_len - 1)
		ft_putptr_base(new_nb / base_len, base, base_len);
	mod = new_nb % base_len;
	write (1, &base[mod], 1);
}
