/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:23:29 by vkorniie          #+#    #+#             */
/*   Updated: 2018/06/08 11:20:05 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	find_x_y(t_window **w, t_fdf *ptr)
{
	(*w)->x_elem = ptr->x_count;
	(*w)->y_elem = ptr->y_count;
	(*w)->start_x = 0;
	(*w)->start_y = 0;
	(*w)->an_x = 0;
	(*w)->an_y = 0;
	(*w)->an_z = 0;
}

void	open_window(t_fdf *ptr)
{
	t_window	*i;

	i = (t_window *)malloc(sizeof(t_window));
	i->ptr = ptr;
	i->mlx_ptr = mlx_init();
	i->win_ptr = mlx_new_window(i->mlx_ptr, HEIGHT, WIDTH, "FDF VKorniie");
	i->k = fmin((HEIGHT / 2) / ptr->x_count, (HEIGHT / 2) / ptr->y_count);
	find_x_y(&i, ptr);
	rotate(i);
	change_coor(&ptr, i);
	line(i, ptr);
	write_hint(i);
	mlx_hook(i->win_ptr, 2, 5, hadle_input_key, i);
	mlx_loop(i->mlx_ptr);
}

int		hadle_input_key(int key, t_window *window)
{
	t_fdf *new;
	t_fdf *tmp;

	new = window->ptr;
	tmp = window->ptr;
	if (key == 53)
		exit(0);
	change_map(key, window);
	rotate(window);
	change_coor(&window->ptr, window);
	line(window, window->ptr);
	write_hint(window);
	return (0);
}

void	write_hint(t_window *ptr)
{
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 200, 1050, 0x66C7ED,
		"Change size: + -");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 200, 1150, 0x66C7ED,
		"Rotate: 1, 2, 3, 4, 5, 6");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 200, 1100, 0x66C7ED,
		"Move: < /\\ \\/ >");
}

void	change_coor(t_fdf **ptr, t_window *w)
{
	t_fdf	*new;

	new = *ptr;
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	center_coor(w);
	while (new)
	{
		new->temp_x = ((HEIGHT / 2) + (new->r_x - w->m_x) * w->k)
			+ w->start_x;
		new->temp_y = ((WIDTH / 2) + (new->r_y - w->m_y) * w->k)
			+ w->start_y;
		new = new->next;
	}
}
