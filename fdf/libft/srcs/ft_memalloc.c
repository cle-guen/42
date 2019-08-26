/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:58:32 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/16 14:23:19 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = (void*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size + 1)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
