/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prime_sum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:01:06 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 11:08:15 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_prime_sum(unsigned int number)
{
	unsigned int i;
	unsigned int sum;

	i = 2;
	sum = 0;
	while (i <= number)
	{
		if (ft_is_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}
