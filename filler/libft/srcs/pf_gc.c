/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 02:34:04 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/07 14:23:56 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_gc(t_flags *flags, va_list al, t_pos *pos, char *str)
{
	wchar_t	c;

	(void)str;
	if (al)
		c = va_arg(al, wchar_t);
	else
		return (1);
	if (flags->minus == 0)
		pf_w_width(flags, pos, c);
	pf_put_wchar(pos, c);
	if (flags->minus == 1)
		pf_w_width(flags, pos, c);
	return (1);
}
