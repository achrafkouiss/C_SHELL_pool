/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:50:21 by akouiss           #+#    #+#             */
/*   Updated: 2025/09/01 04:55:24 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*new_arr;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	new_arr = malloc(sizeof(int) * size);
	if (!new_arr)
		return (-1);
	*range = new_arr;
	i = 0;
	while (min < max)
	{
		new_arr[i] = min;
		min++;
		i++;
	}
	return (size);
}
