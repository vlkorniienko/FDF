/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:37:00 by vkorniie          #+#    #+#             */
/*   Updated: 2018/03/28 12:37:30 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s)
	{
		while (i < start)
			i++;
		p = (char *)malloc(sizeof(char) * len + 1);
		if (p == NULL)
			return (0);
		while (j < len && s[i] != '\0')
			p[j++] = s[i++];
		p[j] = '\0';
		return (p);
	}
	return (0);
}
