/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:47:13 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/22 11:51:12 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		if (!(out = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[start + i] && i < len)
		{
			out[i] = s[start + i];
			i++;
		}
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}
