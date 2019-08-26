/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 02:58:59 by cle-guen          #+#    #+#             */
/*   Updated: 2018/05/29 16:31:16 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_precision(t_flags *flags, t_pos *pos, int bol)
{
	int		tmp;

	tmp = flags->pre;
	while (tmp > 0 && flags->point == bol)
	{
		pf_put_buff(pos, "0", 1);
		tmp--;
	}
}
