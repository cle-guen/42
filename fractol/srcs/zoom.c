/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:22:03 by cle-guen          #+#    #+#             */
/*   Updated: 2018/04/05 17:40:42 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_env *e)
{
	double	t_x;
	double	t_y;

	t_x = e->mouse_x / (double)WIN_W * (e->x_max - e->x_min) + e->x_min;
	t_y = e->mouse_y / (double)WIN_H * (e->y_max - e->y_min) + e->y_min;
	e->x_min = t_x - (t_x - e->x_min) * 0.8;
	e->x_max = t_x + (e->x_max - t_x) * 0.8;
	e->y_min = t_y - (t_y - e->y_min) * 0.8;
	e->y_max = t_y + (e->y_max - t_y) * 0.8;
	e->stepx = (e->x_max - e->x_min) / (double)WIN_W;
	e->stepy = (e->y_max - e->y_min) / (double)WIN_H;
	e->zoom++;
}

void	zoom_out(t_env *e)
{
	double	t_x;
	double	t_y;

	t_x = e->mouse_x / (double)WIN_W * (e->x_max - e->x_min) + e->x_min;
	t_y = e->mouse_y / (double)WIN_H * (e->y_max - e->y_min) + e->y_min;
	e->x_min = t_x - (t_x - e->x_min) / 0.8;
	e->x_max = t_x + (e->x_max - t_x) / 0.8;
	e->y_min = t_y - (t_y - e->y_min) / 0.8;
	e->y_max = t_y + (e->y_max - t_y) / 0.8;
	e->stepx = (e->x_max - e->x_min) / (double)WIN_W;
	e->stepy = (e->y_max - e->y_min) / (double)WIN_H;
	e->zoom--;
}
