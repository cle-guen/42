/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 06:15:58 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/05 14:38:36 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_c(t_flags *flags, va_list al, t_pos *pos, char *str)
{
	char	c;

	if (flags->mod == l)
	{
		if (str[pos->str_index] == 'c')
			pf_gc(flags, al, pos, str);
		else
			pf_gc(flags, NULL, pos, str);
		return (1);
	}
	str += pos->str_index;
	flags->width -= 1;
	if (*str == 'c')
	{
		c = (char)va_arg(al, int);
		pf_width(flags, pos, 0);
		pf_put_buff(pos, &c, 1);
	}
	else if (*str > 0)
	{
		pf_width(flags, pos, 0);
		pf_put_buff(pos, &*str, 1);
	}
	pf_width(flags, pos, 1);
	return (1);
}
