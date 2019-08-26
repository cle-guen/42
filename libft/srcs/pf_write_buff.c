/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_write_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:48:36 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/06 13:10:46 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_write_buff(t_pos *pos, int ret)
{
	t_buff	*tmp;

	pos->buff = pos->first;
	if (!pos->error)
	{
		while (pos->buff)
		{
			tmp = pos->buff;
			ret += write(1, pos->buff->content, pos->buff->index);
			pos->buff = pos->buff->next;
			free(tmp);
		}
		return (ret);
	}
	else
	{
		write(1, pos->buff->content, pos->i_error);
		while (pos->buff)
		{
			tmp = pos->buff;
			pos->buff = pos->buff->next;
			free(tmp);
		}
		return (-1);
	}
}
