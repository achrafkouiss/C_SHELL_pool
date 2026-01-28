/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:13:51 by akouiss           #+#    #+#             */
/*   Updated: 2025/08/27 14:59:30 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*new_arr;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	size = max - min;
	new_arr = malloc(sizeof(int) * size);
	if (!new_arr)
		return (NULL);
	while (min < max)
	{
		new_arr[i] = min;
		i++;
		min++;
	}
	return (new_arr);
}
