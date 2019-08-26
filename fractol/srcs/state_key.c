/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:26:21 by cle-guen          #+#    #+#             */
/*   Updated: 2018/04/05 17:46:03 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_env *e)
{
	if (keycode == H_KEY)
		e->state[H_KEY] = (e->state[H_KEY] == 1 ? 0 : 1);
	else if (keycode == COLOR_NEXT)
	{
		e->theme++;
		if (e->theme == 4)
			e->theme = 0;
	}
	else if (keycode == COLOR_PREV)
	{
		e->theme--;
		if (e->theme == -1)
			e->theme = 3;
	}
	else if (keycode == PAUSE)
		e->state[PAUSE] = (e->state[PAUSE] == 1 ? 0 : 1);
	else
		e->state[keycode] = 1;
	return (0);
}

int		key_release(int keycode, t_env *e)
{
	if (keycode == H_KEY || keycode == PAUSE)
		return (0);
	e->state[keycode] = 0;
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *e)
{
	if (y > 0 && y < WIN_H && x > 0 && x < WIN_W)
	{
		x = y;
		e->mouse[button] = 1;
		if (button == SCROLLUP_KEY && e->zoom < 125)
			zoom_in(e);
		if (button == SCROLLDOWN_KEY && e->zoom > -5)
			zoom_out(e);
		mouse_funct(e);
	}
	return (0);
}

int		mouse_release(int button, int x, int y, t_env *e)
{
	x = y;
	e->mouse[button] = 0;
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (y > 0 && y < WIN_H && x > 0 && x < WIN_W)
	{
		e->mouse_x = x;
		e->mouse_y = y;
		if (e->type == JULIA && e->state[PAUSE] == 1)
		{
			e->c_r = e->mouse_x * e->stepx + e->x_min;
			e->c_i = e->mouse_y * e->stepy + e->y_min;
		}
	}
	return (0);
}
