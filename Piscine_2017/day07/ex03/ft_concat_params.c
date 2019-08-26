/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 01:44:27 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/26 17:13:20 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_size(int argc, char **argv)
{
	int i;
	int j;
	int nb;

	i = 0;
	j = 1;
	nb = 0;
	while (j <= argc - 1)
	{
		while (argv[j][i])
		{
			nb++;
			i++;
		}
		nb++;
		i = 0;
		j++;
	}
	return (nb);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = (char*)malloc(sizeof(char) * ft_size(argc, argv));
	if (str == 0)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (i < argc - 1)
	{
		while (argv[i + 1][j] != 0)
		{
			str[k] = argv[i + 1][j];
			k++;
			j++;
		}
		j = 0;
		str[k] = (i == argc - 2) ? 0 : '\n';
		k++;
		i++;
	}
	return (str);
}
