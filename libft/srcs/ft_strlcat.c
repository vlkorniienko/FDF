/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:46:23 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/03 14:10:45 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen((char *)src) + i);
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (i + j < (dstsize - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (j)
		dst[j + i] = '\0';
	return (ft_strlen((char *)src) + i);
}
