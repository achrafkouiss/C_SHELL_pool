/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:17:00 by akouiss           #+#    #+#             */
/*   Updated: 2025/08/16 13:24:06 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr_continuation(int nb)
{
	int	digits;
	int	copy;
	int	divisor;

	divisor = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	copy = nb;
	while (copy >= 10)
	{
		copy = copy / 10;
		divisor = divisor * 10;
	}
	while (divisor >= 1)
	{
		digits = nb / divisor;
		nb = nb % divisor;
		divisor = divisor / 10;
		ft_putchar(digits + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else
	{
		ft_putnbr_continuation(nb);
	}
}
