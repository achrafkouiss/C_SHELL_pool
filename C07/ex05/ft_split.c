/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:19:18 by akouiss           #+#    #+#             */
/*   Updated: 2025/09/03 03:39:01 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	checkchar(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (checkchar(str[i], charset) && str[i])
			i++;
		if (str[i])
			count++;
		while (!checkchar(str[i], charset) && str[i])
			i++;
	}
	return (count);
}

int	ft_sstrlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (checkchar(str[i], charset))
			return (i);
		i++;
	}
	return (i);
}

char	*ft_allo(char *str, char *charset)
{
	int		i;
	int		len;
	char	*string;

	i = 0;
	len = ft_sstrlen(str, charset) + 1;
	string = malloc(sizeof(char) * len);
	if (!string)
		return (NULL);
	while (!checkchar(str[i], charset) && str[i])
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		size;
	char	**strings;

	i = 0;
	j = 0;
	size = count_words(str, charset) + 1;
	strings = malloc(sizeof(char *) * size);
	if (!strings)
		return (NULL);
	while (str[i])
	{
		while (checkchar(str[i], charset) && str[i])
			i++;
		if (str[i])
			strings[j++] = ft_allo(&str[i], charset);
		while (!checkchar(str[i], charset) && str[i])
			i++;
	}
	strings[j] = NULL;
	return (strings);
}
