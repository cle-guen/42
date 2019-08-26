/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:02:55 by cle-guen          #+#    #+#             */
/*   Updated: 2018/05/30 17:58:54 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_go_mod(t_flags *flags, va_list al, uintmax_t *n)
{
	if (flags->point == 1)
		flags->zero = 0;
	*n = va_arg(al, unsigned long);
}

static void	pf_go_bis(t_flags *flags, t_pos *pos, uintmax_t *n)
{
	pf_width(flags, pos, 0);
	if (*n == 0 && flags->point == 0 && flags->sharp == 1)
		flags->sharp = 0;
	if (flags->sharp == 1 && *n != 0)
		pf_put_buff(pos, "0", 1);
	pf_precision(flags, pos, 1);
}

int			pf_go(t_flags *flags, va_list al, t_pos *pos)
{
	char		*str;
	int			len;
	uintmax_t	n;
	int			start_pre;

	pf_go_mod(flags, al, &n);
	str = pf_itoa_base(flags, n, "01234567", 8);
	start_pre = n == 0 && flags->point == 1 && flags->sharp == 0 &&
		flags->pre == 0 ? 0 : 1;
	len = pf_strlen(str);
	flags->pre -= len + (flags->sharp == 1 && n != 0);
	flags->pre *= (flags->pre >= 0);
	flags->width -= (flags->sharp == 1 && flags->pre < len) +
		(len + flags->pre) - (n == 0 && flags->point == 1 && flags->pre == 0) -
		(n == 0 && flags->point == 0 && flags->sharp == 1);
	pf_go_bis(flags, pos, &n);
	if (start_pre)
		pf_put_buff(pos, str, len);
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	pf_width(flags, pos, 1);
	free(str);
	return (1);
}
