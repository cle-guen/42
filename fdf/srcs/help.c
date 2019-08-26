/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:57:27 by cle-guen          #+#    #+#             */
/*   Updated: 2018/01/31 15:27:55 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	help(char **tab)
{
	tab[0] = "  CONTROLS";
	tab[1] = "W     |   UP";
	tab[2] = "S     |   DOWN";
	tab[3] = "A     |   LEFT";
	tab[4] = "D     |   RIGHT";
	tab[5] = "UP    |   INCREASE ALT";
	tab[6] = "DOWN  |   DECREASE ALT";
	tab[7] = "LEFT  |   CLOCKWISE";
	tab[8] = "RIGHT |   ANTICLOCKWISE";
	tab[9] = "<     |   REMOVE LAYER";
	tab[10] = ">     |   ADD LAYER";
	tab[11] = "+     |   ZOOM IN";
	tab[12] = "-     |   ZOOM OUT";
	tab[13] = "0     |   RESET";
	tab[14] = "1-5   |   THEMES";
	tab[15] = NULL;
}
