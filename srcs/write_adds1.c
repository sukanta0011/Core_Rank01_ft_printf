#include "ft_printf.h"

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

void	print_ptr(void *ptr, char fmt)
{
	char				*hex_base;
	// unsigned int		ptr_size;
	unsigned long		num;

	// ptr_size = sizeof(ptr);
	num = (unsigned long)ptr;
	hex_base = "0123456789abcdef";
	if (fmt == 'p')
	{
		ft_putstr("0x");
		ft_putptr_base(num, hex_base, ft_strlen(hex_base));
	}
}
