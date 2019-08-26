/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:00:04 by cle-guen          #+#    #+#             */
/*   Updated: 2018/02/13 15:33:52 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_put_pixels(t_env *env, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*((int *)&env->buff[(env->oct_p_pix * x) + (env->size_line * y)]) = color;
}

static void		draw_line_bis(int *x0, int *y0, t_draw *dist, t_draw *s)
{
	if (s->err2 > -dist->x)
	{
		s->err -= dist->y;
		*x0 += s->x;
	}
	if (s->err2 < dist->y)
	{
		s->err += dist->x;
		*y0 += s->y;
	}
}

void			draw_line(t_env *env, int x0, int y0, t_draw point)
{
	t_draw	dist;
	t_draw	s;

	dist.x = abs(point.x - x0);
	s.x = x0 < point.x ? 1 : -1;
	dist.y = abs(point.y - y0);
	s.y = y0 < point.y ? 1 : -1;
	s.err = (dist.x > dist.y ? dist.x : -dist.y) / 2;
	s.i = 0;
	s.max = dist.x > dist.y ? dist.x : dist.y;
	while (1)
	{
		if (env->int_min == env->int_max)
			s.color = env->palette[env->theme];
		else
			s.color = ft_color((float)s.i
					/ s.max, env->color[0], env->color[1]);
		ft_put_pixels(env, x0, y0, s.color);
		s.i++;
		if (x0 == point.x && y0 == point.y)
			break ;
		s.err2 = s.err;
		draw_line_bis(&x0, &y0, &dist, &s);
	}
}
