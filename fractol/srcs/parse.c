/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:27:01 by cle-guen          #+#    #+#             */
/*   Updated: 2018/04/16 17:27:44 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	parse_bis(t_env *e, char *str)
{
	if (ft_strcmp("tricorn", str) == 0)
	{
		e->type = TRICORN;
		set_tricorn(e);
		return (1);
	}
	else if (ft_strcmp("eye", str) == 0)
	{
		e->type = EYE;
		set_man_eye_cel(e);
		return (1);
	}
	else if (ft_strcmp("celtic", str) == 0)
	{
		e->type = CELTIC;
		set_man_eye_cel(e);
		return (1);
	}
	return (0);
}

int			parse(t_env *e, char *str)
{
	if (parse_bis(e, str) == 1)
		return (1);
	else if (ft_strcmp("mandelbrot", str) == 0)
	{
		e->type = MANDELBROT;
		set_man_eye_cel(e);
		return (1);
	}
	else if (ft_strcmp("julia", str) == 0)
	{
		e->type = JULIA;
		set_julia(e);
		return (1);
	}
	else if (ft_strcmp("burningship", str) == 0)
	{
		e->type = BURNINGSHIP;
		set_burningship(e);
		return (1);
	}
	else
		usage();
	return (0);
}
