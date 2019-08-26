/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:41:37 by cle-guen          #+#    #+#             */
/*   Updated: 2018/11/05 14:58:20 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	init_heat_map(t_map *map)
{
	int	i;

	i = 0;
	if (!(map->heat_map = (int **)ft_memalloc(sizeof(int *) * (map->h + 1))))
		return (-1);
	while (i < map->h)
	{
		if (!(map->heat_map[i] = (int *)malloc(sizeof(int) * (map->w + 1))))
			return (-1);
		ft_memset(map->heat_map[i], 127, map->w * sizeof(int));
		i++;
	}
	return (0);
}

static int	fill_tab(t_map *map, t_point point, int dist)
{
	if (point.y < 0 || point.x < 0 || point.y >= map->h || point.x >= map->w)
		return (0);
	if (dist != 0 && map->heat_map[point.y][point.x] <= dist)
		return (0);
	map->heat_map[point.y][point.x] = dist;
	fill_tab(map, (t_point){point.y + 1, point.x}, dist + 1);
	fill_tab(map, (t_point){point.y - 1, point.x}, dist + 1);
	fill_tab(map, (t_point){point.y, point.x + 1}, dist + 1);
	fill_tab(map, (t_point){point.y, point.x - 1}, dist + 1);
	return (0);
}

int			calcul_heat_map(t_map *map)
{
	t_point point;

	point = (t_point){0, 0};
	if (map->heat_map == NULL)
		if (init_heat_map(map) < 0)
			return (-1);
	while (point.y < map->h)
	{
		point.x = 0;
		while (point.x < map->w)
		{
			if (map->map[point.y][point.x] == map->devil)
				fill_tab(map, point, 0);
			point.x++;
		}
		point.y++;
	}
	return (0);
}
