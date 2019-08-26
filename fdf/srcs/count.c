/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:09:45 by cle-guen          #+#    #+#             */
/*   Updated: 2018/02/13 17:02:12 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count(char *line)
{
	int			i;
	int			cnt;
	static int	first = 0;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			cnt++;
			while (line[i] && line[i] != ' ')
				i++;
		}
		else
			i++;
	}
	if (first == 0)
		first = cnt;
	if (cnt != first)
		not_valid();
	return (cnt);
}
