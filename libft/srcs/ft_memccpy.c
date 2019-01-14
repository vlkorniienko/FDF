/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:54:45 by vkorniie          #+#    #+#             */
/*   Updated: 2018/03/30 10:36:42 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *i;
	unsigned char *j;

	i = (unsigned char *)dst;
	j = (unsigned char *)src;
	while (n--)
	{
		*i++ = *j++;
		if (*(i - 1) == (unsigned char)c)
			return (i);
	}
	return (NULL);
}
