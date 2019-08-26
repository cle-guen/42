/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:06:42 by cle-guen          #+#    #+#             */
/*   Updated: 2018/11/05 14:57:37 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_map	map;
	t_piece	piece;
	t_point	point;

	map = (t_map){NULL, NULL, 0, 0, 0, 0};
	piece = (t_piece){NULL, 0, 0};
	point = (t_point){0, 0};
	if (set_player(&map) < 0)
		return (0);
	while (1)
	{
		if (set_map(&map) < 0)
			break ;
		if (set_piece(&piece) < 0)
			break ;
		if (calcul_heat_map(&map) < 0)
			break ;
		if (algo(&map, &piece) > 0)
			break ;
	}
	free_map(&map);
	free_piece(&piece);
	return (0);
}
