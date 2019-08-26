/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:00:48 by cle-guen          #+#    #+#             */
/*   Updated: 2018/05/31 01:42:21 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_h(t_flags *flags)
{
	if (flags->mod > h)
		return (0);
	if (flags->mod == none)
		flags->mod = h;
	else if (flags->mod == h)
		flags->mod = hh;
	else
		flags->mod = h;
	return (0);
}
