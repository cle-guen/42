/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 15:17:30 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/26 17:10:34 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	*range = (int*)malloc(sizeof(int) * len);
	if (*range == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		*(range[0] + i) = min;
		i++;
		min++;
	}
	return (len);
}
