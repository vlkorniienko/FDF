/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:41:49 by vkorniie          #+#    #+#             */
/*   Updated: 2018/06/09 16:27:20 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/incs/libft.h"
# include <mlx.h>
# include <math.h>

# define HEIGHT 1800
# define WIDTH 1200

typedef struct		s_fdf
{
	double			x;
	double			y;
	double			z;
	double			temp_x;
	double			temp_y;
	double			r_x;
	double			r_y;
	double			r_z;
	int				x_count;
	int				y_count;
	unsigned int	color;
	struct s_fdf	*right;
	struct s_fdf	*down;
	struct s_fdf	*next;
}					t_fdf;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			k;
	double			start_x;
	double			start_y;
	double			an_x;
	double			an_y;
	double			an_z;
	double			m_x;
	double			m_y;
	int				x_elem;
	int				y_elem;
	struct s_fdf	*ptr;
}					t_window;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				length_x;
	int				length_y;
	int				length;
}					t_line;

int					count_elem(char **str, int i);
void				make_struct(char *line, t_fdf **ptr);
int					find_next(t_fdf *fdf);
void				read_map(char **argv);

t_fdf				*write_coordinates(int i, int j, char **str);
int					find_down(t_fdf **list);
unsigned int		atoi_base(char *s, int base);
int					check_map(int fd, int line_lenght, int line_count);
void				open_window(t_fdf *ptr);
void				line(t_window *it, t_fdf *ptr);
void				algorithm(t_fdf *ptr, t_window *wind, t_fdf *susid);
void				write_pixel(t_fdf *ptr, t_window *w, t_line *temp);
void				put_first_line(t_fdf *ptr, t_window *w, t_line *temp);
void				put_second_line(t_fdf *ptr, t_window *w, t_line *temp);
void				change_coor(t_fdf **ptr, t_window *window);

void				find_elements(t_fdf **structs);
void				write_hint(t_window *ptr);
void				change_map(int key, t_window *ptr);
int					hadle_input_key(int key, t_window *window);
void				find_x_y(t_window **w, t_fdf *ptr);
void				rotate(t_window *ptr);
void				center_coor(t_window *ptr);

#endif
