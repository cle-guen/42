/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 23:16:06 by cle-guen          #+#    #+#             */
/*   Updated: 2018/05/31 01:43:28 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_l(t_flags *flags)
{
	if (flags->mod > l)
		return (0);
	if (flags->mod == none)
		flags->mod = l;
	else if (flags->mod == l)
		flags->mod = ll;
	else
		flags->mod = l;
	return (0);
}
