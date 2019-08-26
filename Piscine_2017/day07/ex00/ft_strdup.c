/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:26:46 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/26 17:08:21 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		length;
	int		i;

	i = 0;
	length = 0;
	while (src[length] != 0)
		length++;
	copy = (char*)malloc(sizeof(char) * (length + 1));
	if (copy == NULL)
		return (0);
	while (i <= length)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
