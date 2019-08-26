/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:09:24 by cle-guen          #+#    #+#             */
/*   Updated: 2018/01/15 17:51:44 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntwrd(char const *s, char c)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt += 1;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static int	ft_wordlen(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		ii;
	char	**tab;
	int		wrd_len;

	if (s != NULL)
	{
		i = 0;
		ii = 0;
		if (!(tab = (char **)malloc(sizeof(char *) * cntwrd(s, c) + 1)))
			return (NULL);
		while (s[ii])
			if (s[ii] != c)
			{
				wrd_len = ft_wordlen(s + ii, c);
				tab[i++] = ft_strsub(s, ii, wrd_len);
				ii += wrd_len;
			}
			else
				ii++;
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}
