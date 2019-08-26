/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_gx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:43:05 by cle-guen          #+#    #+#             */
/*   Updated: 2018/05/30 14:20:05 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_gx_mod(t_flags *flags, va_list al, uintmax_t *n)
{
	if (flags->point == 1)
		flags->zero = 0;
	if (flags->mod == none)
		*n = va_arg(al, unsigned int);
	if (flags->mod == l)
		*n = va_arg(al, unsigned long);
	if (flags->mod == ll)
		*n = va_arg(al, unsigned long long);
	if (flags->mod == h)
		*n = (unsigned short)va_arg(al, unsigned int);
	if (flags->mod == hh)
		*n = (unsigned char)va_arg(al, unsigned int);
	if (flags->mod == j)
		*n = va_arg(al, uintmax_t);
	if (flags->mod == z)
		*n = va_arg(al, size_t);
}

static void	pf_gx_bis(t_flags *flags, t_pos *pos, uintmax_t *n)
{
	if (flags->zero == 0)
		pf_width(flags, pos, 0);
	if (flags->sharp == 1 && *n > 0)
		pf_put_buff(pos, "0X", 2);
	if (flags->zero == 1)
		pf_width(flags, pos, 0);
	pf_precision(flags, pos, 1);
}

int			pf_gx(t_flags *flags, va_list al, t_pos *pos)
{
	char		*str;
	int			len;
	uintmax_t	n;
	int			start_pre;

	start_pre = flags->pre;
	pf_gx_mod(flags, al, &n);
	str = pf_itoa_base(flags, n, "0123456789ABCDEF", 16);
	len = pf_strlen(str);
	flags->pre -= len;
	flags->pre *= (flags->pre >= 0);
	flags->width -= 2 * (flags->sharp == 1 && n != 0) +
		(len + flags->pre) - (n == 0 && flags->point == 1 && flags->pre == 0);
	pf_gx_bis(flags, pos, &n);
	if (!(n == 0 && !start_pre && flags->point == 1))
		pf_put_buff(pos, str, len);
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	pf_width(flags, pos, 1);
	free(str);
	return (1);
}
