/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:34:25 by vkorniie          #+#    #+#             */
/*   Updated: 2018/03/22 17:38:29 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *r;

	r = (unsigned char *)b;
	if (len == 0)
		return (b);
	while (len)
	{
		*r++ = (unsigned char)c;
		len--;
	}
	return (b);
}
