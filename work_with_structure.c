/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:33:54 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/01 02:35:17 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			parse_structure(t_map *map, char *line, int y)
{
	int			x;
	char		**str;
	static int	npixel;

	str = ft_strsplit(line, ' ');
	x = 0;
	while (x < map->str_len)
	{
		map->picture[npixel].x = x;
		map->picture[npixel].y = y;
		map->picture[npixel].z = ft_atoi(str[x]);
		x++;
		npixel++;
	}
	free_split(str);
}

int				start_parse_structure(t_map *map, char *mapname)
{
	char		*line;
	int			y;
	int			fd;

	fd = open(mapname, O_RDONLY);
	y = 0;
	while ((line = get_next_line_fd(fd)))
	{
		parse_structure(map, line, y);
		free(line);
		y++;
	}
	close(fd);
	return (0);
}
