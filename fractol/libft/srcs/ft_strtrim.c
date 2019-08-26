/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:28:15 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/29 17:24:06 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;

	if (s != NULL)
	{
		start = 0;
		end = ft_strlen(s) - 1;
		while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
			start++;
		if (!s[start])
			return (ft_strnew(0));
		while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
			end--;
		len = end - start;
		return (ft_strsub(s, start, len + 1));
	}
	return (NULL);
}
