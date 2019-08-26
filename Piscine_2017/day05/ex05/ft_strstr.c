/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 00:25:32 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/20 16:59:59 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int lenfind;
	int	i;
	int	j;
	int	n;

	lenfind = ft_strlen(to_find);
	i = 0;
	j = 0;
	if (lenfind == 0)
		return (str);
	while (str[i] != '\0')
	{
		n = i;
		while (str[i] == to_find[j])
		{
			j++;
			i++;
			if (j == lenfind)
				return (&str[i - lenfind]);
		}
		j = 0;
		i = n + 1;
	}
	return (0);
}
