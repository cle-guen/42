/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:33:11 by cle-guen          #+#    #+#             */
/*   Updated: 2018/04/16 17:30:47 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_input(t_env *e)
{
	double	h;
	double	w;

	if (e->state[UP_KEY] || e->state[DOWN_KEY])
	{
		h = (e->state[DOWN_KEY] ? -(e->y_max - e->y_min) * 0.05 :
		(e->y_max - e->y_min) * 0.05);
		e->y_min += h;
		e->y_max += h;
	}
	if (e->state[LEFT_KEY] || e->state[RIGHT_KEY])
	{
		w = (e->state[RIGHT_KEY] ? -(e->x_max - e->x_min) * 0.05 :
		(e->x_max - e->x_min) * 0.05);
		e->x_min += w;
		e->x_max += w;
	}
}

static void	sec_input_funct(t_env *e)
{
	if (e->state[ITER_MORE] && e->iter < 500)
		e->iter += 5;
	if (e->state[ITER_LESS] && e->iter > 10)
		e->iter -= 5;
	if (e->state[ESC] == 1)
		close_program(e);
	if (e->state[RESET] == 1)
	{
		if (e->type == MANDELBROT || e->type == EYE || e->type == CELTIC)
			set_man_eye_cel(e);
		if (e->type == JULIA)
			set_julia(e);
		if (e->type == BURNINGSHIP)
			set_burningship(e);
		if (e->type == TRICORN)
			set_tricorn(e);
	}
}

static void	third_input_funct(t_env *e)
{
	if (e->state[KEY_4] == 1)
	{
		set_tricorn(e);
		e->type = TRICORN;
	}
	if (e->state[KEY_5] == 1)
	{
		set_man_eye_cel(e);
		e->type = EYE;
	}
	if (e->state[KEY_6] == 1)
	{
		set_man_eye_cel(e);
		e->type = CELTIC;
	}
}

int			input_funct(t_env *e)
{
	move_input(e);
	sec_input_funct(e);
	third_input_funct(e);
	if (e->state[KEY_1] == 1)
	{
		set_man_eye_cel(e);
		e->type = MANDELBROT;
	}
	if (e->state[KEY_2] == 1)
	{
		set_julia(e);
		e->type = JULIA;
	}
	if (e->state[KEY_3] == 1)
	{
		set_burningship(e);
		e->type = BURNINGSHIP;
	}
	return (0);
}
