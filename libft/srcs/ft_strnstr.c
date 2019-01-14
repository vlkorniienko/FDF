/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:26:49 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 13:38:11 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)s);
	while (i < len && s[i] != '\0')
	{
		j = 0;
		while (needle[j] == s[i + j] && needle[j] != '\0')
		{
			if (needle[j + 1] == '\0' && (i + j) < len)
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
