/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:33:30 by akouiss           #+#    #+#             */
/*   Updated: 2025/08/25 09:12:32 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	count;

	i = 2;
	count = 0;
	if (nb == 0 || nb == 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			count++;
		i++;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
