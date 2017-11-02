/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:28:58 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/01 02:29:44 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	modify_cords(t_map *map)
{
	int	i;
	int	count_c;

	count_c = map->str_len * map->map_y;
	i = 0;
	while (count_c)
	{
		map->picture[i].x =
				(map->picture[i].x - 1) - map->str_len / 2;
		map->picture[i].y =
				(map->picture[i].y - 1) - map->map_y / 2;
		count_c--;
		i++;
	}
}

void	init_first_cam(t_fdf *fdf)
{
	fdf->scale = 30;
	fdf->angle[2] = 0.35;
	fdf->angle[0] = -0.95;
}

void	min1(t_fdf *fdf, t_pixel *p1)
{
	fdf->d[4] = (fdf->d[1] << 1) - fdf->d[0];
	fdf->d[5] = fdf->d[1] << 1;
	fdf->d[6] = (fdf->d[1] - fdf->d[0]) << 1;
	mlx_pixel_put(fdf->mlx, fdf->win, p1->x_r, p1->y_r, 0xDC143C);
	fdf->d[7] = p1->x_r + fdf->d[2];
	fdf->d[8] = p1->y_r;
	fdf->d[9] = 1;
	while (fdf->d[9] <= fdf->d[0])
	{
		if (fdf->d[4] > 0)
		{
			fdf->d[4] += fdf->d[6];
			fdf->d[8] += fdf->d[3];
		}
		else
			fdf->d[4] += fdf->d[5];
		mlx_pixel_put(fdf->mlx, fdf->win,
				fdf->d[7], fdf->d[8], 0xFFFF00);
		fdf->d[7] += fdf->d[2];
		fdf->d[9]++;
	}
}

void	min2(t_fdf *fdf, t_pixel *p1)
{
	fdf->d[4] = (fdf->d[0] << 1) - fdf->d[1];
	fdf->d[5] = fdf->d[0] << 1;
	fdf->d[6] = (fdf->d[0] - fdf->d[1]) << 1;
	mlx_pixel_put(fdf->mlx, fdf->win, p1->x_r, p1->y_r, 0xFFFFFF);
	fdf->d[8] = p1->y_r + fdf->d[3];
	fdf->d[7] = p1->x_r;
	fdf->d[9] = 1;
	while (fdf->d[9] <= fdf->d[1])
	{
		if (fdf->d[4] > 0)
		{
			fdf->d[4] += fdf->d[6];
			fdf->d[7] += fdf->d[2];
		}
		else
			fdf->d[4] += fdf->d[5];
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->d[7],
				fdf->d[8], 0xFFFFFF);
		fdf->d[9]++;
		fdf->d[8] += fdf->d[3];
	}
}

void	drawline(t_pixel *p1, t_pixel *p2, t_fdf *fdf)
{
	fdf->d[0] = abs(p2->x_r - p1->x_r);
	fdf->d[1] = abs(p2->y_r - p1->y_r);
	fdf->d[2] = p2->x_r >= p1->x_r ? 1 : -1;
	fdf->d[3] = p2->y_r >= p1->y_r ? 1 : -1;
	if (fdf->d[1] <= fdf->d[0])
		min1(fdf, p1);
	else
		min2(fdf, p1);
}
