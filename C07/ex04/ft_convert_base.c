/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:42:15 by akouiss           #+#    #+#             */
/*   Updated: 2025/09/03 12:13:08 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_convert_from_base(char *nbr, char *base_from, int i);
char	*ft_itoa_base(long nbr, char *base_to);

int	checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		count;
	long	rest;
	char	*str;

	i = 0;
	count = 0;
	rest = 0;
	if (!checkbase(base_from) || !checkbase(base_to))
		return (NULL);
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			count++;
		i++;
	}
	rest = ft_convert_from_base(nbr, base_from, i);
	if (count % 2 == 1)
		rest = -rest;
	str = ft_itoa_base(rest, base_to);
	return (str);
}
