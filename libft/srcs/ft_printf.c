/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:40:56 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/06 13:11:49 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse(t_pos *pos, va_list al, const char *str, int (*f[256])())
{
	t_flags	flags;

	flags = (t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0, none};
	if (!(str[pos->str_index]))
		return (0);
	while (f[(unsigned char)str[pos->str_index]](&flags, al, pos, str) == 0)
	{
		if (!(str[pos->str_index]))
			return (0);
		pos->str_index++;
	}
	if (!pos->error)
		pos->i_error = pos->buff->index;
	return (1);
}

static void	init_tab_bis(int (*f[256])())
{
	f['#'] = pf_sharp;
	f['0'] = pf_zero;
	f['-'] = pf_minus;
	f['+'] = pf_plus;
	f[' '] = pf_space;
	f['.'] = pf_point;
	f['*'] = pf_star;
	f['h'] = pf_h;
	f['l'] = pf_l;
	f['j'] = pf_j;
	f['z'] = pf_z;
	f['c'] = pf_c;
	f['C'] = pf_gc;
	f['S'] = pf_gs;
	f['s'] = pf_s;
	f['d'] = pf_d;
	f['i'] = pf_d;
	f['D'] = pf_gd;
	f['o'] = pf_o;
	f['O'] = pf_go;
	f['u'] = pf_u;
	f['U'] = pf_gu;
	f['x'] = pf_x;
	f['X'] = pf_gx;
	f['p'] = pf_p;
}

static void	init_tab(int (*f[256])())
{
	int	i;

	i = 0;
	while (i < 256)
	{
		f[i] = pf_c;
		i++;
	}
	i = '0';
	while (i <= '9')
		f[i++] = pf_get_value;
	init_tab_bis(f);
}

static void	init_var(t_pos *pos)
{
	pos->str_index = 0;
	pos->error = 0;
	pos->i_error = 0;
	pos->first = pf_create_buffer();
	pos->buff = pos->first;
}

int			ft_printf(const char *str, ...)
{
	va_list		al;
	t_pos		pos;
	static int	(*f[256])() = {NULL};

	init_var(&pos);
	init_tab(f);
	va_start(al, str);
	while (str[pos.str_index] && !pos.error)
	{
		if (str[pos.str_index] == '%')
		{
			pos.str_index++;
			if (parse(&pos, al, str, f) == 0)
				break ;
		}
		else
			pf_put_buff(&pos, (char *)&str[pos.str_index], 1);
		if (str[pos.str_index])
			pos.str_index++;
	}
	va_end(al);
	return (pf_write_buff(&pos, 0));
}
