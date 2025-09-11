/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:55:22 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 09:55:22 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	print_nbr(int num, char fmt)
{
	char	*cap_hex_base;
	char	*hex_base;
	char	*dec_base;

	cap_hex_base = "0123456789ABCDEF";
	hex_base = "0123456789abcdef";
	dec_base = "0123456789";
	if (fmt == 'd' || fmt == 'i' || fmt == 'u')
		ft_putnbr_base(num, dec_base, ft_strlen(dec_base));
	if (fmt == 'x')
		ft_putnbr_base(num, hex_base, ft_strlen(hex_base));
	if (fmt == 'X')
		ft_putnbr_base(num, cap_hex_base, ft_strlen(cap_hex_base));
}
