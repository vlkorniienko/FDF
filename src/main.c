/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:32:48 by vkorniie          #+#    #+#             */
/*   Updated: 2018/06/09 16:34:01 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		count_elem(char **str, int i)
{
	char	**s;
	int		res;
	int		j;

	res = 0;
	s = ft_strsplit(*str, ' ');
	while (s[res])
		res++;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if ((!ft_isdigit(s[i][j]) && s[i][j] != 45 &&
				!ft_isdigit(s[i][j + 1]) && !ft_isalpha(s[i][j])) ||
				(s[i][j] == 44 && s[i][j + 1] != '0' && s[i][j + 2] != 'x'))
				return (-1);
			j++;
		}
		i++;
	}
	while (i--)
		free(s[i]);
	free(s);
	return (res);
}

t_fdf	*write_coordinates(int i, int j, char **str)
{
	t_fdf	*ptr;
	char	*find;

	ptr = (t_fdf *)malloc(sizeof(t_fdf));
	ptr->x = i;
	ptr->temp_x = i;
	ptr->y = j;
	ptr->temp_y = j;
	ptr->z = ft_atoi(str[i]);
	ptr->r_x = i;
	ptr->r_y = j;
	ptr->r_z = ptr->z;
	if ((find = ft_strchr(str[i], ',')))
	{
		find += 3;
		ptr->color = atoi_base(find, 16);
	}
	else
		ptr->color = 0xFFFFFF;
	ptr->down = NULL;
	ptr->right = NULL;
	ptr->next = NULL;
	return (ptr);
}

void	make_struct(char *line, t_fdf **ptr)
{
	t_fdf		*tmp;
	int			i;
	char		**str;
	static int	counter = 0;

	i = 0;
	str = ft_strsplit(line, ' ');
	if (!*ptr)
	{
		*ptr = write_coordinates(i, counter, str);
		i++;
	}
	tmp = *ptr;
	while (tmp->next)
		tmp = tmp->next;
	while (str[i])
	{
		tmp->next = write_coordinates(i, counter, str);
		i++;
		tmp = tmp->next;
	}
	while (i--)
		free(str[i]);
	free(str);
	counter++;
}

int		check_map(int fd, int line_lenght, int line_count)
{
	char	*line;
	int		tmp;

	while (get_next_line(fd, &line) > 0)
	{
		line_lenght = count_elem(&line, 0);
		if ((line_lenght == -1) || (tmp != line_lenght && line_count != 0))
		{
			ft_putendl("Invalid map");
			exit(0);
		}
		tmp = line_lenght;
		line_count++;
		free(line);
	}
	if (get_next_line(fd, &line) == -1)
	{
		ft_putendl("Usage: ./fdf [file name]");
		exit(0);
	}
	free(line);
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;
	int ret;
	int line_count;
	int line_lenght;

	line_count = 0;
	line_lenght = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [file name]");
		return (0);
	}
	if ((ret = check_map(fd, line_lenght, line_count)))
		close(fd);
	read_map(argv);
	return (0);
}
