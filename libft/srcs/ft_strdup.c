/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:55:27 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 13:18:28 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		srclen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i + 1);
}

char			*ft_strdup(const char *s1)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = srclen(s1);
	p = (char *)malloc(sizeof(char) * j);
	if (p == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
