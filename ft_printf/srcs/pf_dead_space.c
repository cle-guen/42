/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dead_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:52:49 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/06 14:59:17 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_dead_space(t_pos *pos, t_flags *flags, int pre, wchar_t *str)
{
	int	diff;
	int	i;

	diff = 0;
	i = 0;
	while (str[i] && pre >= 0 && flags->width > 0)
	{
		diff = pf_len_wchar(str[i]);
		pre -= diff;
		i++;
	}
	if (pre < 0)
	{
		diff += pre;
		while (diff > 0)
		{
			pf_put_buff(pos, " ", 1);
			diff--;
		}
	}
}
