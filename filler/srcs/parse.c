/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:05:55 by cle-guen          #+#    #+#             */
/*   Updated: 2018/11/05 14:58:34 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_len(unsigned int nb)
{
	int		len;

	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int			set_player(t_map *map)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (-1);
	if (line[10] == '2')
	{
		map->player = 'X';
		map->devil = 'O';
	}
	else
	{
		map->player = 'O';
		map->devil = 'X';
	}
	free(line);
	return (0);
}

int			set_piece(t_piece *piece)
{
	char	*line;
	int		i;

	i = 0;
	if (piece->piece != NULL)
		free_piece(piece);
	if (get_next_line(0, &line) <= 0)
		return (-1);
	piece->ph = ft_atoi(line + 6);
	piece->pw = ft_atoi(line + (6 + get_len(piece->ph)));
	free(line);
	if (!(piece->piece = (char **)ft_memalloc(sizeof(char *)
		* (piece->ph + 1))))
		return (-1);
	while (i < piece->ph)
	{
		if (get_next_line(0, &(piece->piece[i])) <= 0)
			return (-1);
		i++;
	}
	return (0);
}

static int	init_map(t_map *map)
{
	int	i;

	i = 0;
	if (!(map->map = (char **)ft_memalloc(sizeof(char *) * (map->h + 1))))
		return (-1);
	while (i < map->h)
	{
		if (!(map->map[i] = (char *)ft_memalloc(sizeof(char) * (map->w + 1))))
			return (-1);
		i++;
	}
	return (0);
}

int			set_map(t_map *map)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) <= 0)
		return (-1);
	map->h = ft_atoi(line + 8);
	map->w = ft_atoi(line + (9 + get_len(map->h)));
	free(line);
	if (get_next_line(0, &line) <= 0)
		return (-1);
	free(line);
	if (map->map == NULL && init_map(map) < 0)
		return (-1);
	i = 0;
	while (i < map->h)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		ft_strcpy(map->map[i], line + 4);
		free(line);
		i++;
	}
	return (0);
}
