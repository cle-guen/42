/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:19:35 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/11 16:19:44 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		length;
	int		index;
	char	*end;
	char	tmp;

	length = ft_strlen(str);
	end = str + length - 1;
	index = 0;
	while (index < (length / 2))
	{
		tmp = *str;
		*str = *end;
		*end = tmp;
		str++;
		end--;
		index++;
	}
	return (str - index);
}
