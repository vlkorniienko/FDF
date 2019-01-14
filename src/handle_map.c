/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:16:50 by vkorniie          #+#    #+#             */
/*   Updated: 2018/06/09 16:31:20 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void	change_map(int key, t_window *window)
{
	if (key == 69)
		window->k += 4;
	else if (key == 78 && window->k > 4)
		window->k -= 4;
	else if (key == 124)
		window->start_x += 3;
	else if (key == 123)
		window->start_x -= 3;
	else if (key == 125)
		window->start_y += 3;
	else if (key == 126)
		window->start_y -= 3;
	else if (key == 83)
		window->an_x += 0.05;
	else if (key == 84)
		window->an_y += 0.05;
	else if (key == 85)
		window->an_z += 0.05;
	else if (key == 86)
		window->an_x -= 0.05;
	else if (key == 87)
		window->an_y -= 0.05;
	else if (key == 88)
		window->an_z -= 0.05;
}

void	center_coor(t_window *ptr)
{
	double		x[2];
	double		y[2];
	t_fdf		*temp;

	temp = ptr->ptr;
	x[0] = ptr->ptr->r_x;
	x[1] = ptr->ptr->r_x;
	y[0] = ptr->ptr->r_y;
	y[1] = ptr->ptr->r_y;
	while (temp)
	{
		if (temp->r_x < x[0])
			x[0] = temp->r_x;
		else if (temp->r_x > x[1])
			x[1] = temp->r_x;
		if (temp->r_y < y[0])
			y[0] = temp->r_y;
		else if (temp->r_y > y[1])
			y[1] = temp->r_y;
		temp = temp->next;
	}
	ptr->m_x = (x[0] + x[1]) / 2;
	ptr->m_y = (y[0] + y[1]) / 2;
}

void	rotate(t_window *ptr)
{
	double		tx;
	double		ty;
	double		tz;
	t_fdf		*n;

	n = ptr->ptr;
	while (n)
	{
		tx = n->x;
		ty = n->y;
		tz = n->z;
		n->r_y = ty * cos(ptr->an_x) + tz * -sin(ptr->an_x);
		n->r_z = ty * sin(ptr->an_x) + tz * cos(ptr->an_x);
		tz = n->r_z;
		n->r_x = tx * cos(ptr->an_y) + tz * sin(ptr->an_y);
		n->r_z = tx * -sin(ptr->an_y) + tz * cos(ptr->an_y);
		ty = n->r_y;
		tx = n->r_x;
		n->r_x = tx * cos(ptr->an_z) + ty * -sin(ptr->an_z);
		n->r_y = tx * sin(ptr->an_z) + ty * cos(ptr->an_z);
		n = n->next;
	}
}
