/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:24:36 by cle-guen          #+#    #+#             */
/*   Updated: 2018/11/05 15:00:58 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_piece(t_map *map, t_piece *piece, t_point point)
{
	t_point	p;
	int		link;
	int		score;

	p.y = 0;
	link = 0;
	score = 0;
	while (p.y < piece->ph)
	{
		p.x = -1;
		while (++p.x < piece->pw)
		{
			if (piece->piece[p.y][p.x] == '*')
			{
				if (p.x + point.x < 0 || p.y + point.y < 0
						|| p.x + point.x >= map->w || p.y + point.y >= map->h
						|| map->map[point.y + p.y][point.x + p.x] == map->devil)
					return (0);
				score += map->heat_map[point.y + p.y][point.x + p.x];
				link += (map->map[point.y + p.y][point.x + p.x] == map->player);
			}
		}
		p.y++;
	}
	return ((link == 1) * score);
}

int			algo(t_map *map, t_piece *piece)
{
	t_point	point;
	t_point	saved;
	t_point	distances;

	saved = (t_point){0, 0};
	distances = (t_point){INT_MAX, 0};
	point.y = -piece->ph;
	while (point.y < map->h)
	{
		point.x = -piece->pw;
		while (point.x < map->w)
		{
			if ((distances.x = check_piece(map, piece, point)) > 0)
				if (distances.x < distances.y)
				{
					saved.y = point.y;
					saved.x = point.x;
					distances.y = distances.x;
				}
			point.x++;
		}
		point.y++;
	}
	ft_printf("%d %d\n", saved.y, saved.x);
	return (distances.y == INT_MAX);
}
