/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:35:48 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 09:23:40 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	i = 0;
	if (s2 < s1)
		while (len)
		{
			*(s2 + i) = *(s1 + i);
			i++;
			len--;
		}
	else
		while (len--)
			s2[len] = s1[len];
	return (dst);
}
