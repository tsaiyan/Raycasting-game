/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:29:13 by tsaiyan           #+#    #+#             */
/*   Updated: 2021/01/28 18:29:15 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARCER_MAP_H
#define PARCER_MAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "mms/mlx.h"
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

#define SCALE 16 // условный размер каждого квадратика в карте
#define FOOT 0.3 // шаг шага

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	int			vert;
	int			gorisont;
}				  t_win;

typedef struct	s_map //структура для карты
{
	char *no_way;
	char *so_way;
	char *we_way;
	char *ea_way;
	char *s_way;
	char *floor_color;
	char *sky_color;
	int total_lines_before_map;
	int error;
	int lines;
}				  t_map;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
	char		plook;
}				  t_plr;

typedef struct	s_all // структура для всего вместе
{
	t_win		win;
	t_plr		plr;
	t_map		map;
	char		**array;
	char		**arrrecuv;
}				  t_all;


// for map:
void	ft_map_parcer(t_all *all, char *argv);
int		config_map(t_all *all, char *str);
void	ft_putin(t_all *all);
char	**make_map(t_list **head, int size, t_all *all);
void	map_copy(t_all *all);
int		check_ways(t_all *all);
int		error(t_all *all);
int		map_validate(t_all *all);
int		find_player(t_all *all);
int		bad_chars_in_map(t_all *all);
#endif /* parcer_map_h */
