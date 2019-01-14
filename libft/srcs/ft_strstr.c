/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 08:26:05 by vkorniie          #+#    #+#             */
/*   Updated: 2018/03/26 10:58:01 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	str1 = (char *)haystack;
	str2 = (char *)needle;
	i = 0;
	if ((str1[0] == '\0' && str2[0] == '\0') || str2[0] == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		j = 0;
		if (str1[i] == str2[j])
		{
			while (str2[j] == str1[i + j] && str2[j] != '\0')
			{
				if (str2[j] == str1[i + j] && str2[j + 1] == '\0')
					return (str1 + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
