/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:28:27 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/01 02:28:43 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		calc_x_p1(t_pixel *p1, t_fdf *fdf)
{
	double	x0;
	double	z0;
	double	tmp;

	x0 = p1->x * fdf->scale;
	z0 = p1->z * fdf->upz;
	tmp = x0;
	x0 = tmp * cos(fdf->angle[1]) + z0 * sin(fdf->angle[1]);
	z0 = (-tmp * sin(fdf->angle[1]) + z0 * cos(fdf->angle[1]));
	return (x0);
}

double		calc_y_p1(t_pixel *p1, t_fdf *fdf)
{
	double	y0;
	double	z0;
	double	tmp;

	y0 = p1->y * fdf->scale;
	z0 = p1->z * fdf->upz;
	tmp = y0;
	y0 = (tmp * cos(fdf->angle[0]) + z0 * sin(fdf->angle[0]));
	z0 = (-tmp * sin(fdf->angle[0]) + z0 * cos(fdf->angle[0]));
	return (y0);
}

double		calc_x_p2(t_pixel *p2, t_fdf *fdf)
{
	double	x1;
	double	z1;
	double	tmp;

	x1 = p2->x * fdf->scale;
	z1 = p2->z * fdf->upz;
	tmp = x1;
	x1 = tmp * cos(fdf->angle[1]) + z1 * sin(fdf->angle[1]);
	z1 = (-tmp * sin(fdf->angle[1]) + z1 * cos(fdf->angle[1]));
	return (x1);
}

double		calc_y_p2(t_pixel *p2, t_fdf *fdf)
{
	double	y1;
	double	z1;
	double	tmp;

	y1 = p2->y * fdf->scale;
	z1 = p2->z * fdf->upz;
	tmp = y1;
	y1 = (tmp * cos(fdf->angle[0]) + z1 * sin(fdf->angle[0]));
	z1 = (-tmp * sin(fdf->angle[0]) + z1 * cos(fdf->angle[0]));
	return (y1);
}

void		calculate_point(t_pixel *p1, t_pixel *p2, t_fdf *fdf)
{
	double	x0;
	double	y0;
	double	tmp;
	double	x1;
	double	y1;

	y0 = calc_y_p1(p1, fdf);
	x0 = calc_x_p1(p1, fdf);
	tmp = x0;
	x0 = tmp * cos(fdf->angle[2]) + y0 * sin(fdf->angle[2]);
	y0 = -tmp * sin(fdf->angle[2]) + y0 * cos(fdf->angle[2]);
	x0 += fdf->shift_x + SCR_W / 2;
	y0 += fdf->shift_y + SCR_H / 2;
	y1 = calc_y_p2(p2, fdf);
	x1 = calc_x_p2(p2, fdf);
	tmp = x1;
	x1 = tmp * cos(fdf->angle[2]) + y1 * sin(fdf->angle[2]);
	y1 = -tmp * sin(fdf->angle[2]) + y1 * cos(fdf->angle[2]);
	x1 += fdf->shift_x + SCR_W / 2;
	y1 += fdf->shift_y + SCR_H / 2;
	p1->x_r = (int)x0;
	p1->y_r = (int)y0;
	p2->x_r = (int)x1;
	p2->y_r = (int)y1;
	drawline(p1, p2, fdf);
}
