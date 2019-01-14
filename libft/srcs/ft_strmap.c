/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:10:24 by vkorniie          #+#    #+#             */
/*   Updated: 2018/03/28 11:33:43 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*p;

	i = 0;
	if (s)
	{
		p = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (p == NULL)
			return (0);
		while (s[i] != '\0')
		{
			p[i] = (*f)(s[i]);
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
