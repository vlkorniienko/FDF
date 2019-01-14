/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:16:14 by vkorniie          #+#    #+#             */
/*   Updated: 2018/06/08 11:19:21 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			find_elements(t_fdf **str)
{
	t_fdf *new;

	new = *str;
	while (new->next)
		new = new->next;
	(*str)->x_count = new->x + 1;
	(*str)->y_count = new->y + 1;
}

void			read_map(char **argv)
{
	t_fdf	*ptr;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	ptr = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		make_struct(line, &ptr);
		free(line);
	}
	close(fd);
	find_elements(&ptr);
	find_next(ptr);
}

int				find_down(t_fdf **list)
{
	t_fdf	*ptr;
	t_fdf	*tmp;

	ptr = *list;
	while (ptr && ptr->y == 0)
		ptr = ptr->next;
	tmp = *list;
	while (ptr)
	{
		tmp->down = ptr;
		ptr = ptr->next;
		tmp = tmp->next;
	}
	return (0);
}

int				find_next(t_fdf *fdf)
{
	t_fdf	*ptr;
	t_fdf	*tmp;

	tmp = fdf;
	ptr = fdf;
	while (ptr->next)
	{
		if (ptr->y == ptr->next->y)
			ptr->right = ptr->next;
		ptr = ptr->next;
	}
	find_down(&fdf);
	open_window(fdf);
	return (0);
}

unsigned int	atoi_base(char *str, int base)
{
	unsigned int	i;
	int				k;

	i = 0;
	k = 0;
	if (!str)
		return (0);
	while (str[k] == ' ' || (str[k] >= 9 && str[k] <= 13))
	{
		i++;
		k++;
	}
	while (str[k] && ((ft_isdigit(str[k]) || (str[k] >= 'A' && str[k] <= 'F'))
		|| (str[k] >= 'a' && str[k] <= 'f')))
	{
		i = (i * base);
		if (str[k] < 97)
			i += (str[k] - (str[k] <= 57 ? 48 : 55));
		else
			i += str[k] - 87;
		k++;
	}
	return (i);
}
