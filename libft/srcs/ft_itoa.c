/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:15:33 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 13:17:52 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(int i)
{
	int temp;
	int j;

	temp = i;
	j = 0;
	if (i <= 0)
		j++;
	while (temp)
	{
		temp = temp / 10;
		j++;
	}
	return (j);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*p;
	int		i;

	size = checker(n);
	i = 0;
	p = ft_memalloc(size + 1);
	if (p == NULL)
		return (0);
	p[size--] = '\0';
	if (n == 0)
		p[0] = 48;
	while (n)
	{
		p[size] = (n > 0) ? n % 10 + 48 : (n % 10 * -1 + 48);
		n = n / 10;
		size--;
	}
	if (p[0] == 0)
		p[0] = '-';
	return (p);
}
