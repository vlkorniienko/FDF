/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:45:55 by vkorniie          #+#    #+#             */
/*   Updated: 2018/03/30 11:19:56 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;
	size_t			count;

	i = (unsigned char *)s1;
	j = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (i[count] > j[count] || i[count] < j[count])
			return (i[count] - j[count]);
		count++;
	}
	return (0);
}
