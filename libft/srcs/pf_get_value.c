/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:48:48 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/05 15:02:58 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_width(t_flags *flags, t_pos *pos, char *str)
{
	flags->width = 0;
	flags->star = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		flags->width *= 10;
		flags->width += *str - '0';
		str++;
		pos->str_index++;
	}
}

static void	get_pre(t_flags *flags, t_pos *pos, char *str)
{
	while (*str && *str >= '0' && *str <= '9')
	{
		flags->pre *= 10;
		flags->pre += *str - '0';
		str++;
		pos->str_index++;
	}
}

int			pf_get_value(t_flags *flags, va_list al, t_pos *pos, char *str)
{
	(void)al;
	if (flags->point == 0)
	{
		if (flags->width == 0 || flags->star == 1)
		{
			str += pos->str_index;
			get_width(flags, pos, str);
			pos->str_index--;
		}
	}
	else
	{
		if (flags->pre == 0)
		{
			str += pos->str_index;
			get_pre(flags, pos, str);
			pos->str_index--;
		}
	}
	return (0);
}
