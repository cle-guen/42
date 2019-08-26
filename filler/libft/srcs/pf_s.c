/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:21:25 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/11 16:25:29 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_s_bis(t_flags *flags, t_pos *pos, int *len, char *str)
{
	if (flags->width && flags->pre && *len == 0)
	{
		while (flags->width != 0)
		{
			pf_put_buff(pos, " ", 1);
			flags->width--;
		}
	}
	if (flags->point == 1)
	{
		if (flags->pre < *len)
			*len = flags->pre;
		flags->width -= *len;
	}
	else
		flags->width -= *len;
	pf_width(flags, pos, 0);
	if (flags->point == 0)
		pf_put_buff(pos, str, *len);
	if (flags->point == 1)
		pf_put_buff(pos, str, *len);
	pf_width(flags, pos, 1);
}

int			pf_s(t_flags *flags, va_list al, t_pos *pos, char *str)
{
	int		len;

	len = 0;
	if (flags->mod == l && al)
	{
		pf_gs(flags, al, pos);
		return (1);
	}
	if (al)
		str = va_arg(al, char*);
	if (str)
	{
		if (!(flags->pre == 0 && flags->point == 1))
			len = pf_strlen(str);
		pf_s_bis(flags, pos, &len, str);
	}
	else
		pf_s(flags, NULL, pos, "(null)");
	return (1);
}
