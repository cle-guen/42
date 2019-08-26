/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:55:16 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/28 11:31:01 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	list = NULL;
	if (lst)
	{
		list = ft_lstnew(lst->content, lst->content_size);
		list = f(lst);
		list->next = ft_lstmap(lst->next, f);
	}
	return (list);
}
