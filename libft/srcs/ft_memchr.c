/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:29:02 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 20:05:06 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *i;

	i = (unsigned char *)s;
	while (n)
	{
		if (*i++ == (unsigned char)c)
			return (i - 1);
		else
			n--;
	}
	return (NULL);
}
