/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 05:46:14 by akouiss           #+#    #+#             */
/*   Updated: 2025/08/26 21:32:15 by akouiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	sum;

	sum = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
