/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:18:49 by cle-guen          #+#    #+#             */
/*   Updated: 2018/04/16 16:17:06 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc_fract_sec(t_env *e, t_calcul *c)
{
	if (e->type == JULIA)
	{
		c->c_r = e->c_r;
		c->c_i = e->c_i;
		c->z_r = c->tmpx;
		c->z_i = c->tmpy;
		c->i = 0;
	}
	else
	{
		c->c_r = c->tmpx;
		c->c_i = c->tmpy;
		c->z_r = 0;
		c->z_i = 0;
		c->i = 0;
	}
}

static void	calc_fract_third(t_env *e, t_calcul *c)
{
	c->tmp = c->z_r;
	if (e->type == CELTIC)
		c->z_r = fabs((c->z_r * c->z_r) - (c->z_i * c->z_i)) + c->c_r;
	else if (e->type == EYE)
		c->z_r = c->z_r * c->z_r + c->z_i * c->z_i + c->c_r;
	else
		c->z_r = c->z_r * c->z_r - c->z_i * c->z_i + c->c_r;
	if (e->type == BURNINGSHIP)
		c->z_i = 2 * fabs(c->z_i * c->tmp) + c->c_i;
	else if (e->type == TRICORN || e->type == CELTIC)
		c->z_i = -2 * c->z_i * c->tmp + c->c_i;
	else if (e->type == EYE)
		c->z_i = -2 * fabs(c->z_r) * c->z_i + c->c_i;
	else
		c->z_i = 2 * c->z_i * c->tmp + c->c_i;
	c->i++;
}

void		calc_fract(t_env *e, int thread, double xt_min)
{
	t_calcul c;

	c.x = (WIN_W / THREAD) * thread;
	c.stop = (WIN_W / THREAD) * (thread + 1);
	c.tmpx = xt_min;
	while (c.x < c.stop)
	{
		c.y = 0;
		c.tmpy = e->y_min;
		while (c.y < WIN_H)
		{
			calc_fract_sec(e, &c);
			while (c.z_r * c.z_r + c.z_i * c.z_i < 4 && c.i < e->iter)
				calc_fract_third(e, &c);
			if (c.i != e->iter)
				ft_put_pixels(e, c.x, c.y, c.i * e->tab_c[e->theme]);
			c.tmpy += e->stepy;
			c.y++;
		}
		c.tmpx += e->stepx;
		c.x++;
	}
}
