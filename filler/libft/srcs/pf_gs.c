/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_gs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 02:36:46 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/11 16:25:25 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_put_wstring_bis(t_pos *pos, t_flags *flags, wchar_t *wstr)
{
	while (*wstr && flags->pre - pf_len_wchar(*wstr) >= 0)
	{
		if (flags->pre > 0)
			pf_put_wchar(pos, *wstr);
		flags->pre -= pf_len_wchar(*wstr);
		wstr++;
	}
}

static void	pf_put_wstring(t_pos *pos, t_flags *flags, wchar_t *wstr)
{
	int		pre;

	pre = flags->pre;
	if (flags->pre > 0 && *wstr)
	{
		if (!flags->minus)
			pf_dead_space(pos, flags, pre, wstr);
		pf_put_wstring_bis(pos, flags, wstr);
		if (flags->minus)
			pf_dead_space(pos, flags, pre, wstr);
	}
	else
	{
		if (flags->point)
			return ;
		while (*wstr)
		{
			pf_put_wchar(pos, *wstr);
			wstr++;
		}
	}
}

static void	pf_gs_v2(t_flags *flags, t_pos *pos, int tmp_width, wchar_t *wstr)
{
	while (tmp_width > 0)
	{
		pf_put_buff(pos, flags->zero ? "0" : " ", 1);
		tmp_width--;
	}
	pf_put_wstring(pos, flags, wstr);
}

static void	pf_gs_v3(t_flags *flags, t_pos *pos, int tmp_width, wchar_t *wstr)
{
	pf_put_wstring(pos, flags, wstr);
	while (tmp_width > 0)
	{
		pf_put_buff(pos, flags->zero ? "0" : " ", 1);
		tmp_width--;
	}
}

int			pf_gs(t_flags *flags, va_list al, t_pos *pos)
{
	wchar_t	*wstr;
	int		len;
	int		tmp_width;

	len = 0;
	wstr = va_arg(al, wchar_t *);
	tmp_width = flags->width;
	if (wstr)
	{
		if (flags->point == 0 || (flags->point && flags->pre > 0))
		{
			len = pf_len_wstring(wstr);
			tmp_width -= (*wstr && flags->pre > 0) ? flags->pre : len;
		}
		if (flags->minus == 0)
			pf_gs_v2(flags, pos, tmp_width, wstr);
		else
			pf_gs_v3(flags, pos, tmp_width, wstr);
	}
	else
		pf_s(flags, NULL, pos, "(null)");
	return (1);
}
