/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:30:50 by cle-guen          #+#    #+#             */
/*   Updated: 2018/01/30 15:19:01 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(float t, int col_a, int col_b)
{
	t_col	a;
	t_col	b;
	t_col	c;

	a.color = col_a;
	b.color = col_b;
	c.argb.a = 0;
	c.argb.b = a.argb.b + (b.argb.b - a.argb.b) * t;
	c.argb.g = a.argb.g + (b.argb.g - a.argb.g) * t;
	c.argb.r = a.argb.r + (b.argb.r - a.argb.r) * t;
	return (c.color);
}
