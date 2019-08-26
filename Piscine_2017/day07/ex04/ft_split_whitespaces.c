/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 00:49:46 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/26 17:21:03 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_calcul_first_tab(char *str)
{
	int		i;
	int		number_words;

	i = 0;
	number_words = 0;
	while (str[i] != 0)
	{
		if (!(str[i] == 9 || str[i] == 32 || str[i] == 13))
		{
			number_words++;
			while (str[i] != 0 && !(str[i] == 9 ||
						str[i] == 32 || str[i] == 13))
				i++;
		}
		if (str[i] != 0)
			i++;
	}
	return (number_words);
}

int		*ft_calcul_second_tab(char *str, int *size_words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] != 0)
	{
		if (!(str[i] == 9 || str[i] == 32 || str[i] == 13))
		{
			while (str[i] != 0 && !(str[i] == 9 ||
						str[i] == 32 || str[i] == 13))
			{
				len++;
				i++;
			}
			size_words[j] = len;
			j++;
			len = 0;
		}
		if (str[i])
			i++;
	}
	return (size_words);
}

char	**ft_cut_words(char *str, char **tab)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (str[i])
	{
		if (!(str[i] == 9 || str[i] == 32 || str[i] == 13))
		{
			while (str[i] && !(str[i] == 9 || str[i] == 32 || str[i] == 13))
			{
				tab[n][j] = str[i];
				j++;
				i++;
			}
			tab[n][j] = 0;
			n++;
			j = 0;
		}
		i = (str[i]) ? i + 1 : i;
	}
	tab[n] = 0;
	return (tab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		number_words;
	int		*size_words;
	int		i;

	i = 0;
	number_words = ft_calcul_first_tab(str);
	if (!(size_words = (int *)malloc(sizeof(int) * number_words)))
		return (0);
	size_words = ft_calcul_second_tab(str, size_words);
	if (!(tab = (char **)malloc(sizeof(char *) * (number_words + 1))))
		return (0);
	while (i < number_words)
	{
		if (!(tab[i] = malloc(sizeof(char) * size_words[i] + sizeof(char))))
			return (0);
		i++;
	}
	tab = ft_cut_words(str, tab);
	return (tab);
}
