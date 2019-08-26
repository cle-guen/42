/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:15:52 by cle-guen          #+#    #+#             */
/*   Updated: 2017/12/04 12:47:45 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *alst)
{
	int n;

	n = 0;
	while (alst)
	{
		ft_putstr("\n\nLink = ");
		ft_putnbr(n++);
		ft_putstr("\nContent = ");
		write(1, alst->content, alst->content_size);
		ft_putstr("\nContent_size = ");
		ft_putnbr(alst->content_size);
		ft_putstr("\nAdress = ");
		ft_putaddress(alst);
		ft_putstr("\nAdress next = ");
		ft_putaddress(alst->next);
		alst = alst->next;
	}
	ft_putstr("\nEnd\n");
	ft_putstr("--------------------------\n");
}
