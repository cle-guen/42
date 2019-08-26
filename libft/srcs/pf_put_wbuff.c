/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_wbuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 02:48:39 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/06 15:18:46 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_len_wchar(wchar_t c)
{
	if (c > 0x10FFFF || (c >= 0xD800 && c <= 0xDFFF))
		return (0);
	if (c >= 0)
	{
		if (c <= 0x007F + 0x7F * (MB_CUR_MAX == 1))
			return (1);
		else if (c >= 0x0080 && c <= 0x07FF)
			return (2);
		else if (c >= 0x0800 && c <= 0xFFFF)
			return (3);
		else if (c >= 0x10000 && c <= 0x10FFFF)
			return (4);
	}
	return (0);
}

int			pf_len_wstring(wchar_t *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
		len += pf_len_wchar(str[i++]);
	return (len);
}

static void	pf_put_wchar_bis(t_pos *pos, wchar_t c, int len)
{
	if (len == 1)
		pos->buff->content[pos->buff->index++] = c;
	else if (len == 2)
	{
		pos->buff->content[pos->buff->index++] = (0x1F & (c >> 6)) | 0xC0;
		pos->buff->content[pos->buff->index++] = (0x3F & c) | 0x80;
	}
	else if (len == 3)
	{
		pos->buff->content[pos->buff->index++] = (0xF & (c >> 12)) | 0xE0;
		pos->buff->content[pos->buff->index++] = (0x3F & (c >> 6)) | 0x80;
		pos->buff->content[pos->buff->index++] = (0x3F & c) | 0x80;
	}
	else if (len == 4)
	{
		pos->buff->content[pos->buff->index++] = (0x7 & (c >> 18)) | 0xF0;
		pos->buff->content[pos->buff->index++] = (0x3F & (c >> 12)) | 0x80;
		pos->buff->content[pos->buff->index++] = (0x3F & (c >> 6)) | 0x80;
		pos->buff->content[pos->buff->index++] = (0x3F & c) | 0x80;
	}
	else
		pos->error = 1;
}

int			pf_put_wchar(t_pos *pos, wchar_t c)
{
	int		len;

	len = pf_len_wchar(c);
	if (pos->buff->index + len >= BUFF_SIZE)
	{
		pos->buff->next = pf_create_buffer();
		pos->buff = pos->buff->next;
	}
	if (MB_CUR_MAX != 1 && len > 0)
		pf_put_wchar_bis(pos, c, len);
	else
	{
		if (c >= 0 && c < 256)
			pos->buff->content[pos->buff->index++] = c;
		else
			pos->error = 1;
	}
	return (len);
}
