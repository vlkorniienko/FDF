/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:07:47 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 20:16:30 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*p;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	if (s)
	{
		while (*s == 32 || *s == 9 || *s == 10)
			s++;
		if (*s == '\0')
			return (ft_strdup(""));
		j = ft_strlen(s) - 1;
		while (s[j] && (s[j] == 32 || s[j] == 9 || s[j] == 10))
			j--;
		p = (char *)malloc(sizeof(char) * (j + 2));
		if (p == NULL)
			return (0);
		while (++k <= j)
			p[k] = s[k];
		p[k] = '\0';
		return (p);
	}
	return (0);
}
