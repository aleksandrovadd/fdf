/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:30:04 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/01 02:31:10 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_str_len(char *line, t_map *map)
{
	char	**str;
	int		len;

	str = ft_strsplit(line, ' ');
	len = str_len(str);
	if (map->str_len != 0 && len != map->str_len)
		error();
	else
		map->str_len = len;
	free_split(str);
}

int			is_hexadecimal(char c)
{
	if (ft_isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}

int			check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!is_hexadecimal(line[i]) || line[i] != 44 ||
			line[i] != 32 || line[i] != 45)
			return (1);
		i++;
	}
	return (0);
}

int			check_map(t_map *map, char *mapname)
{
	char	*line;
	int		fd;
	int		y;

	fd = open(mapname, O_RDONLY);
	if (fd == -1 && ft_printf("usage: ./fdf [map.fdf]\n"))
		error();
	y = 0;
	while ((line = get_next_line_fd(fd)))
	{
		check_line(line);
		check_str_len(line, map);
		free(line);
		y++;
	}
	map->map_y = y;
	close(fd);
	return (0);
}
