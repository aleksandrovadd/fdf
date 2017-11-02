/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:22:46 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/01 02:24:38 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "ft_printf/src/ft_printf.h"
# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define SCR_H 800
# define SCR_W 1200

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;
	int			x_r;
	int			y_r;
}				t_pixel;

typedef struct	s_map
{
	int			str_len;
	int			map_y;
	t_pixel		*picture;
}				t_map;

typedef struct	s_fdf
{
	void		*win;
	void		*mlx;
	int			shift_x;
	int			shift_y;
	int			scale;
	int			upz;
	int			d[10];
	double		angle[3];
}				t_fdf;

int				check_line(char *line);
void			check_str_len(char *line, t_map *map);
int				check_map(t_map *map, char *mapname);
int				str_len(char **str);
void			free_split(char **str);
void			error(void);
void			initiate_structure(t_map *map, t_fdf *ff);
int				start_parse_structure(t_map *map, char *mapname);
void			parse_structure(t_map *map, char *line, int y);
void			calculate_point(t_pixel *p1, t_pixel *p2, t_fdf *fdf);
void			modify_cords(t_map *map);
void			init_first_cam(t_fdf *fdf);
void			drawline(t_pixel *p1, t_pixel *p2, t_fdf *fdf);

#endif
