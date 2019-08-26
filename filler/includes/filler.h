/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:43:06 by cle-guen          #+#    #+#             */
/*   Updated: 2018/11/05 14:59:39 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct	s_map
{
	char		**map;
	int			**heat_map;
	char		player;
	char		devil;
	int			w;
	int			h;
}				t_map;

typedef struct	s_piece
{
	char		**piece;
	int			pw;
	int			ph;
}				t_piece;

typedef struct	s_point
{
	int			y;
	int			x;
}				t_point;

int				set_player(t_map *map);
int				set_piece(t_piece *piece);
int				set_map(t_map *map);
int				calcul_heat_map(t_map *map);
int				algo(t_map *map, t_piece *piece);
void			free_piece(t_piece *piece);
void			free_map(t_map *map);

#endif
