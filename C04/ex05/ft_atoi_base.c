/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:14:49 by akouiss           #+#    #+#             */
/*   Updated: 2025/08/26 13:27:56 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkbase(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_rest(int i, char *base, char *str)
{
	int	j;
	int	rest;

	rest = 0;
	while (str[i])
	{
		j = 0;
		while (base[j] && str[i] != base[j])
			j++;
		if (!base[j])
			break ;
		rest = rest * ft_strlen(base) + j;
		i++;
	}
	return (rest);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	rest;

	i = 0;
	sign = 1;
	rest = 0;
	if (!ft_checkbase(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = sign * -1;
	rest = ft_rest(i, base, str);
	return (rest * sign);
}
