/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 18:44:37 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/24 19:19:47 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split_whitespaces(char *str);

void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int i;
	int ii;

	i = 0;
	ii = 0;
	while (tab[i] != '\0')
	{
		while (tab[i][ii])
		{
			ft_putchar(tab[i][ii]);
			ii++;
		}
		ft_putchar('\n');
		i++;
		ii = 0;
	}
}
