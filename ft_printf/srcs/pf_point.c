/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 03:05:21 by cle-guen          #+#    #+#             */
/*   Updated: 2018/05/31 01:49:15 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_point(t_flags *flags)
{
	if (flags->pre > 0 && flags->point == 1)
	{
		flags->point = 0;
		flags->pre = 0;
	}
	else
		flags->point = 1;
	return (0);
}
