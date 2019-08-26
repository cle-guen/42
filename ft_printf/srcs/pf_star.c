/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:39:24 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/05 15:01:04 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_star(t_flags *flags, va_list al)
{
	int	w;

	flags->star = 1;
	w = va_arg(al, int);
	if (flags->point)
	{
		if (w < 0)
		{
			flags->pre = 0;
			flags->point = 0;
		}
		else
			flags->pre = w;
	}
	else
	{
		if (w < 0)
		{
			flags->width = -w;
			flags->minus = 1;
		}
		else
			flags->width = w;
	}
	return (0);
}
