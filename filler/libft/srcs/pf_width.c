/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 01:24:59 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/04 14:15:30 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_width(t_flags *flags, t_pos *pos, int bol)
{
	int		tmp;

	tmp = flags->width;
	while (tmp > 0 && flags->minus == bol)
	{
		if (flags->zero == 1)
			pf_put_buff(pos, "0", 1);
		else
			pf_put_buff(pos, " ", 1);
		tmp--;
	}
}

void	pf_w_width(t_flags *flags, t_pos *pos, wchar_t wc)
{
	int		tmp;

	tmp = flags->width;
	tmp -= pf_len_wchar(wc);
	while (tmp > 0)
	{
		pf_put_buff(pos, " ", 1);
		tmp--;
	}
}
