/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:18:02 by cle-guen          #+#    #+#             */
/*   Updated: 2018/04/16 16:43:46 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_man_eye_cel(t_env *e)
{
	e->x_min = -2.1 * (double)WIN_W / (double)WIN_H;
	e->x_max = 0.6 * (double)WIN_W / (double)WIN_H;
	e->y_min = -1.5;
	e->y_max = 1.5;
	e->iter = 50;
	e->zoom = 0;
	e->stepx = (e->x_max - e->x_min) / (double)WIN_W;
	e->stepy = (e->y_max - e->y_min) / (double)WIN_H;
}

void	set_julia(t_env *e)
{
	e->state[PAUSE] = 1;
	e->x_min = -1.2 * (double)WIN_W / (double)WIN_H;
	e->x_max = 1.2 * (double)WIN_W / (double)WIN_H;
	e->y_min = -1.5;
	e->y_max = 1.5;
	e->iter = 50;
	e->zoom = 0;
	e->stepx = (e->x_max - e->x_min) / (double)WIN_W;
	e->stepy = (e->y_max - e->y_min) / (double)WIN_H;
	e->c_r = 0.285;
	e->c_i = 0.01;
}

void	set_burningship(t_env *e)
{
	e->x_min = -2.1 * (double)WIN_W / (double)WIN_H;
	e->x_max = 1.2 * (double)WIN_W / (double)WIN_H;
	e->y_min = -2.1;
	e->y_max = 1.2;
	e->iter = 50;
	e->zoom = 0;
	e->stepx = (e->x_max - e->x_min) / (double)WIN_W;
	e->stepy = (e->y_max - e->y_min) / (double)WIN_H;
}

void	set_tricorn(t_env *e)
{
	e->x_min = -2.1 * (double)WIN_W / (double)WIN_H;
	e->x_max = 1.2 * (double)WIN_W / (double)WIN_H;
	e->y_min = -1.8;
	e->y_max = 1.8;
	e->iter = 50;
	e->zoom = 0;
	e->stepx = (e->x_max - e->x_min) / (double)WIN_W;
	e->stepy = (e->y_max - e->y_min) / (double)WIN_H;
}
