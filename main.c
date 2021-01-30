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


#include "cub3d.h"

//int key_press(int key, t_struct *map)
//{
//	printf("\npress\n");
//	mlx_clear_window(map->mlx, map->win);
//	map->y = 0;
//	map->x = 0;
//	if (key == 13)
//		map->py -= FOOT;
//	if (key == 1)
//		map->py += FOOT;
//	if (key == 0)
//		map->px -= FOOT;
//	if (key == 2)
//		map->px += FOOT;
//	if (key == 53)
//		exit(0);
//	//visual_map(map);
//	return(0);
//}

void printf_checks(t_all *all)
{
	puts("- - -- - - - - - - - - - -- - - ");
	int i = 0;
	while(all->array[i])
		printf("\n%s", all->array[i++]);
	printf("\nR vert			=%d\n", all->win.vert);
	printf("R gor			=%d\n", all->win.gorisont);
	printf("NO texture		=%s\n", all->map.no_way);
	printf("SO texture		=%s\n", all->map.so_way);
	printf("WE texture		=%s\n", all->map.we_way);
	printf("EA texture		=%s\n", all->map.ea_way);
	printf("Sprite texture		=%s\n", all->map.s_way);
	printf("Floor color		=%s\n", all->map.floor_color);
	printf("Sky color		=%s\n", all->map.sky_color);
	printf("Player looks at		=%c\n", all->plr.plook);
	i = 0;
	while(all->arrrecuv[i])
		printf("\n%s", all->arrrecuv[i++]);
	puts("- - -- - - - - - - - - - -- - - ");
}

int main(int argc, char **argv)
{
	t_all *all;
	if (!(all = malloc(sizeof(t_all))))
		return (-1);
	ft_putin(all);
	ft_map_parcer(all, argv[1]);
	if (error(all))
		return (0);
	printf_checks(all);
	return 0;
}

