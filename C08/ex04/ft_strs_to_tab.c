/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:51:38 by akouiss           #+#    #+#             */
/*   Updated: 2025/09/02 11:06:39 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*freememory(t_stock_str *strings, int i)
{
	while (i-- >= 0)
	{
		free(strings[i].str);
		free(strings[i].copy);
	}
	free(strings);
	return (NULL);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*strings;

	strings = malloc (sizeof(t_stock_str) * (ac + 1));
	if (!strings)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		strings[i].str = malloc(ft_strlen(av[i]) + 1);
		if (!strings[i].str)
			return (freememory(strings, i));
		strings[i].copy = malloc(ft_strlen(av[i]) + 1);
		if (!strings[i].copy)
			return (freememory(strings, i));
		strings[i].size = ft_strlen(av[i]);
		ft_strcpy(strings[i].str, av[i]);
		ft_strcpy(strings[i].copy, av[i]);
		i++;
	}
	strings[i].str = 0;
	return (strings);
}
