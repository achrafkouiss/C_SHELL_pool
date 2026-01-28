/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:44:55 by akouiss           #+#    #+#             */
/*   Updated: 2025/08/16 13:25:46 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_digits(int nbr)
{
	ft_putchar(nbr / 10 + '0');
	ft_putchar(nbr % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_digits(a);
			ft_putchar(' ');
			ft_print_digits(b);
			if (a < 98)
				write (1, ", ", 2);
			b++;
		}
		a++;
	}
}
