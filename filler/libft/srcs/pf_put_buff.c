/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:53:33 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/13 16:56:52 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_put_buff(t_pos *pos, char *str, int len)
{
	int	tmp_len;

	if (pos->buff->index + len >= BUFF_SIZE)
	{
		tmp_len = BUFF_SIZE - pos->buff->index;
		pf_memcpy(pos->buff->content + pos->buff->index, str, tmp_len);
		pos->buff->index = BUFF_SIZE;
		pos->buff->next = pf_create_buffer();
		pos->buff = pos->buff->next;
		pf_put_buff(pos, str + tmp_len, len - tmp_len);
		return ;
	}
	pf_memcpy(pos->buff->content + pos->buff->index, str, len);
	pos->buff->index += len;
}
