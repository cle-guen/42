/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:51:09 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/26 13:58:37 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long l;

	l = nb;
	if (l < 0)
	{
		l = l * (-1);
		ft_putchar('-');
	}
	if (l >= 0 && l <= 9)
	{
		ft_putchar(l + '0');
	}
	else
	{
		ft_putnbr(l / 10);
		ft_putchar(l % 10 + '0');
	}
}

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

void	ft_show_tab(struct s_stock_par *par)
{
	int		i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[i].tab);
		i++;
	}
}
