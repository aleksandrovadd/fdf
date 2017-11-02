/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:38:19 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/01 10:49:38 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit((int)param);
	return (0);
}

int			ft_mouse_hook(void)
{
	exit(77);
}

void		initiate_structure(t_map *map, t_fdf *ff)
{
	map->picture = (t_pixel*)malloc(sizeof(t_pixel) *
			(map->map_y * map->str_len + 1));
	ft_bzero(map->picture, sizeof(t_pixel) * (map)->map_y * map->str_len + 1);
	ff->shift_x = 0;
	ff->shift_y = 0;
	ff->scale = 10;
	ff->upz = 5;
	map->picture->x_r = 0;
	map->picture->y_r = 0;
	ff->d[0] = 0;
	ff->angle[0] = 0;
	init_first_cam(ff);
}

void		change_coords(t_map *map, t_fdf *ff)
{
	int		i;
	int		k;
	int		count;

	k = map->str_len - 1;
	count = map->str_len * map->map_y;
	i = -1;
	while (++i < count - 1)
	{
		if (i == k)
			k += map->str_len;
		else
			calculate_point(&map->picture[i], &map->picture[i + 1], ff);
	}
	i = -1;
	while (++i < count - map->str_len)
		calculate_point(&map->picture[i], &map->picture[i + map->str_len], ff);
}

int			main(int ac, char **av)
{
	t_map	*map;
	t_fdf	*ff;

	if (ac != 2 && ft_printf("usage: ./fdf [map.fdf]\n"))
		return (0);
	map = (t_map *)malloc(sizeof(t_map));
	ft_bzero(map, sizeof(t_map));
	check_map(map, av[1]);
	ff = (t_fdf *)malloc(sizeof(t_fdf));
	ft_bzero(ff, sizeof(t_fdf));
	ff->mlx = mlx_init();
	ff->win = mlx_new_window(ff->mlx, SCR_W, SCR_H, "mlx 42");
	initiate_structure(map, ff);
	start_parse_structure(map, av[1]);
	modify_cords(map);
	change_coords(map, ff);
	mlx_key_hook(ff->win, my_key_funct, 0);
	mlx_hook(ff->win, 17, 0L, ft_mouse_hook, &ff);
	mlx_loop(ff->mlx);
	return (0);
}
