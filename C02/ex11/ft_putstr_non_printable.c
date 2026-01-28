/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:05:37 by akouiss           #+#    #+#             */
/*   Updated: 2025/08/20 11:48:25 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	div;
	int	mod;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
		{
			div = str[i] / 16;
			mod = str[i] % 16;
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[div]);
			ft_putchar("0123456789abcdef"[mod]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
