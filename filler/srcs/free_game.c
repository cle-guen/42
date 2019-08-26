/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:45:16 by cle-guen          #+#    #+#             */
/*   Updated: 2018/11/05 14:58:25 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->h)
	{
		free(map->map[i]);
		free(map->heat_map[i]);
		i++;
	}
	free(map->map);
	free(map->heat_map);
}

void	free_piece(t_piece *piece)
{
	int		i;

	i = 0;
	while (i < piece->ph)
	{
		free(piece->piece[i]);
		i++;
	}
	free(piece->piece);
	piece->ph = 0;
	piece->pw = 0;
}
