/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeljoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:09:20 by cle-guen          #+#    #+#             */
/*   Updated: 2017/12/04 12:48:40 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_freeit(t_list *todel)
{
	free(todel->content);
	todel->content_size = 0;
	todel->next = NULL;
	free(todel);
}

void			ft_lstdeljoin(t_list **alst, t_list *todel)
{
	t_list		*first;

	if (alst && *alst && todel)
	{
		first = *alst;
		if (*alst == todel)
		{
			(*alst) = (*alst)->next;
			ft_freeit(todel);
		}
		else
		{
			while ((*alst)->next != todel && (*alst)->next != NULL)
				*alst = (*alst)->next;
			if ((*alst)->next)
			{
				(*alst)->next = todel->next;
				ft_freeit(todel);
			}
			*alst = first;
		}
	}
}
