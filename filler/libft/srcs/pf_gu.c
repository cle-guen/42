/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_gu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:46:02 by cle-guen          #+#    #+#             */
/*   Updated: 2018/05/30 14:02:36 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_gu(t_flags *flags, va_list al, t_pos *pos)
{
	char		*str;
	int			len;
	uintmax_t	n;
	int			start_pre;

	start_pre = flags->pre;
	if (flags->point == 1)
		flags->zero = 0;
	n = va_arg(al, unsigned long);
	str = pf_itoa_base(flags, n, "0123456789", 10);
	len = pf_strlen(str);
	flags->pre -= len;
	flags->pre *= (flags->pre >= 0);
	flags->width -= (len + flags->pre) -
		(n == 0 && flags->point == 1 && flags->pre == 0);
	pf_width(flags, pos, 0);
	pf_precision(flags, pos, 1);
	if (!(n == 0 && !start_pre && flags->point == 1))
		pf_put_buff(pos, str, len);
	pf_width(flags, pos, 1);
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	free(str);
	return (1);
}
