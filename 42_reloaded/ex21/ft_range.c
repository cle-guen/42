/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:50:46 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/09 16:53:45 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * max - min)))
		return (0);
	while (min < max)
	{
		tab[i++] = min;
		min++;
	}
	return (tab);
}
