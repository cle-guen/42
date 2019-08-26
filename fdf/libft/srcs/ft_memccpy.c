/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:59:27 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/13 17:00:43 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*cdst;
	char	*csrc;
	size_t	i;

	cdst = (char*)dst;
	csrc = (char*)src;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if ((unsigned char)csrc[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
