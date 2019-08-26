/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:53:47 by cle-guen          #+#    #+#             */
/*   Updated: 2018/01/31 15:35:32 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int keycode, t_env *env)
{
	env->state[keycode] = 1;
	return (0);
}

int			key_release(int keycode, t_env *env)
{
	env->state[keycode] = 0;
	return (0);
}

static int	key_funct_bis(t_env *env)
{
	if (env->state[ESC] == 1)
		close_program(env);
	if (env->state[RESET] == 1)
		reset(env);
	if (env->state[KEY_1] == 1)
		env->theme = 0;
	if (env->state[KEY_2] == 1)
		env->theme = 2;
	if (env->state[KEY_3] == 1)
		env->theme = 4;
	if (env->state[KEY_4] == 1)
		env->theme = 6;
	if (env->state[KEY_5] == 1)
		env->theme = 8;
	if (env->state[INCREASE_ALT] == 1 || env->state[DECREASE_ALT] == 1)
	{
		env->level += (env->state[DECREASE_ALT] == 1 ? 1 : -1);
		if (env->level < env->int_min)
			env->level = env->int_min;
		if (env->level > env->int_max)
			env->level = env->int_max + 1;
	}
	return (0);
}

static void	tab_help(t_env *env)
{
	char	*tab[16];
	int		i;

	help(tab);
	i = 0;
	while (tab[i])
	{
		mlx_string_put(env->mlx, env->win, 8, 22 * i, 0x00FFFFFF, tab[i]);
		i++;
	}
}

int			key_funct(t_env *env)
{
	if (env->state[UP] == 1 || env->state[DOWN] == 1)
		env->origin_y += (env->state[UP] == 1 ? 20 : -20);
	if (env->state[RIGHT] == 1 || env->state[LEFT] == 1)
		env->origin_x += (env->state[LEFT] == 1 ? 20 : -20);
	if ((env->state[ZOOM_IN] == 1 && env->zoom < 200)
		|| (env->state[ZOOM_OUT] == 1 && env->zoom > 1))
		env->zoom += (env->state[ZOOM_IN] == 1 ? 1 : -1);
	if (env->state[ROTATE_RIGHT] == 1 || env->state[ROTATE_LEFT] == 1)
	{
		env->angle += (env->state[ROTATE_LEFT] == 1 ? RADIAN : -RADIAN);
		env->cos = cos(env->angle);
		env->sin = sin(env->angle);
	}
	if (env->state[ADD_LAYER] == 1 || env->state[REMOVE_LAYER] == 1)
	{
		env->scale += (env->state[REMOVE_LAYER] == 1 ? 1 : -1);
		if (env->scale < 1)
			env->scale = 1;
	}
	key_funct_bis(env);
	trace_fdf(env);
	tab_help(env);
	return (0);
}
