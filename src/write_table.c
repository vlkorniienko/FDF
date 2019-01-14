/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:36:44 by vkorniie          #+#    #+#             */
/*   Updated: 2018/06/05 12:39:18 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	line(t_window *it, t_fdf *ptr)
{
	t_fdf *p;

	p = ptr;
	while (p->next)
	{
		if (p->right)
			algorithm(p, it, p->right);
		if (p->down)
			algorithm(p, it, p->down);
		p = p->next;
	}
}

void	algorithm(t_fdf *ptr, t_window *wind, t_fdf *susid)
{
	t_line *temp;

	if (!(temp = (t_line *)malloc(sizeof(t_line))))
		return ;
	temp->dx = (susid->temp_x - ptr->temp_x >= 0 ? 1 : -1);
	temp->dy = (susid->temp_y - ptr->temp_y >= 0 ? 1 : -1);
	temp->length_x = fabs(susid->temp_x - ptr->temp_x);
	temp->length_y = fabs(susid->temp_y - ptr->temp_y);
	temp->length = fmax(temp->length_x, temp->length_y);
	write_pixel(ptr, wind, temp);
}

void	write_pixel(t_fdf *ptr, t_window *w, t_line *temp)
{
	if (temp->length == 0)
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, ptr->temp_x, ptr->temp_y,
			ptr->color);
		free(temp);
	}
	else if (temp->length_y <= temp->length_x)
		put_first_line(ptr, w, temp);
	else
		put_second_line(ptr, w, temp);
}

void	put_first_line(t_fdf *ptr, t_window *w, t_line *temp)
{
	int x;
	int y;
	int d;

	x = ptr->temp_x;
	y = ptr->temp_y;
	d = -(temp->length_x);
	temp->length++;
	while (temp->length--)
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, x, y, ptr->color);
		x += temp->dx;
		d += 2 * temp->length_y;
		if (d > 0)
		{
			d -= 2 * temp->length_x;
			y += temp->dy;
		}
	}
	free(temp);
}

void	put_second_line(t_fdf *ptr, t_window *w, t_line *temp)
{
	int x;
	int y;
	int d;

	x = ptr->temp_x;
	y = ptr->temp_y;
	d = -(temp->length_y);
	temp->length++;
	while (temp->length--)
	{
		mlx_pixel_put(w->mlx_ptr, w->win_ptr, x, y, ptr->color);
		y += temp->dy;
		d += 2 * temp->length_x;
		if (d > 0)
		{
			d -= 2 * temp->length_y;
			x += temp->dx;
		}
	}
	free(temp);
}
