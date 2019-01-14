/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:36:03 by vkorniie          #+#    #+#             */
/*   Updated: 2018/03/22 15:35:02 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *i;
	unsigned char *j;

	i = (unsigned char *)dst;
	j = (unsigned char *)src;
	while (n)
	{
		*i++ = *j++;
		n--;
	}
	return (dst);
}
