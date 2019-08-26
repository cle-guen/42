/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 09:42:29 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/29 12:43:48 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		u;
	char	*out;

	if (s1 != NULL && s2 != NULL)
	{
		u = ft_strlen(s1) + ft_strlen(s2);
		if (!(out = (char*)malloc(sizeof(char) * u + 1)))
			return (NULL);
		ft_strcpy(out, s1);
		ft_strcat(out, s2);
		return (out);
	}
	return (NULL);
}
