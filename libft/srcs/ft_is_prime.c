/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 10:55:14 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 11:02:10 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(unsigned int number)
{
	unsigned int i;

	i = 2;
	while (i < number)
	{
		if (number % i == 0)
			return (0);
		i++;
	}
	return (1);
}
