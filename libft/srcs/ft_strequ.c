/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:20:45 by vkorniie          #+#    #+#             */
/*   Updated: 2018/03/28 12:21:38 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	char	*str2;

	i = 0;
	str = (char *)s1;
	str2 = (char *)s2;
	if (str && str2)
	{
		while (str[i] == str2[i] && str[i] != '\0' && str2[i] != '\0')
			i++;
		if (str[i] - str2[i] == 0)
			return (1);
		return (0);
	}
	return (0);
}
