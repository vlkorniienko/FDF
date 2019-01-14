/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:43:11 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 19:52:11 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (*alst && del && alst)
	{
		while (*alst)
		{
			temp = (*alst)->next;
			(*del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			*(alst) = NULL;
			*alst = temp;
		}
	}
}
