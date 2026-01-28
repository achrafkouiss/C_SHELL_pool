/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:28:12 by akouiss           #+#    #+#             */
/*   Updated: 2025/08/26 13:32:51 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_checkbase(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_print_base(long nbr, char *base, int len_base)
{
	if (nbr == 0)
		return ;
	ft_print_base(nbr / len_base, base, len_base);
	ft_putchar(base[nbr % len_base]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len_base;
	long	lnbr;

	lnbr = nbr;
	if (!ft_checkbase(base))
		return ;
	len_base = ft_strlen(base);
	if (lnbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	if (lnbr < 0)
	{
		write (1, "-", 1);
		lnbr = -lnbr;
	}
	ft_print_base(lnbr, base, len_base);
}
