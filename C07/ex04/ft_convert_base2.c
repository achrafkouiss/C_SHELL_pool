/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:34:09 by akouiss           #+#    #+#             */
/*   Updated: 2025/09/03 12:13:25 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_convert_from_base(char *nbr, char *base_from, int i)
{
	int	j;
	int	rest;

	rest = 0;
	while (nbr[i])
	{
		j = 0;
		while (base_from[j])
		{
			if (base_from[j] == nbr[i])
				break ;
			j++;
		}
		if (base_from[j])
			rest = rest * ft_strlen(base_from) + j;
		if (!base_from[j])
			break ;
		i++;
	}
	return (rest);
}

int	ft_count(long nbr, char *base_to)
{
	int	count;

	if (nbr == 0)
		return (2);
	count = 1;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr = nbr / ft_strlen(base_to);
		count++;
	}
	return (count);
}

char	*convert_to_base(int count, long nbr, char *base_to, char *str)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		i++;
	}
	str[count--] = '\0';
	while (count >= i)
	{
		str[count] = base_to[nbr % ft_strlen(base_to)];
		nbr = nbr / ft_strlen(base_to);
		count--;
	}
	return (str);
}

char	*ft_itoa_base(long nbr, char *base_to)
{
	int		count;
	char	*str;

	count = ft_count(nbr, base_to);
	str = (char *)malloc(sizeof(char) * count);
	if (!str)
		return (NULL);
	convert_to_base(count - 1, nbr, base_to, str);
	return (str);
}
