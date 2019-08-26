/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_create_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:16:53 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/05 17:16:56 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff		*pf_create_buffer(void)
{
	int		i;
	t_buff	*ret;

	if (!(ret = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	ret->index = 0;
	ret->next = NULL;
	i = 0;
	while (i < BUFF_SIZE)
		ret->content[i++] = '\0';
	return (ret);
}
