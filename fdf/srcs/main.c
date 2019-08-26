/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:58:59 by cle-guen          #+#    #+#             */
/*   Updated: 2018/02/15 14:55:30 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			close_program(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	free(env->map);
	exit(0);
	return (0);
}

void		reset(t_env *env)
{
	int	size_w;
	int	size_h;

	env->scale = 1;
	env->level = 0;
	size_w = WIN_WIDTH / env->width_map;
	size_h = WIN_HEIGHT / (env->height_map + env->int_max);
	env->zoom = size_h < size_w ? size_h : size_w;
	if (env->zoom < 1)
		env->zoom = 1;
	env->origin_x = (WIN_WIDTH / 2) - (env->width_map / 2 * env->zoom);
	env->origin_y = (WIN_HEIGHT / 2) - (env->height_map / 2 * env->zoom);
	env->angle = 0;
	env->cos = cos(env->angle);
	env->sin = sin(env->angle);
}

int			main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf source_file\n");
		return (0);
	}
	ft_bzero(&env.state, sizeof(env.state));
	get_model(&env, argv[1]);
	reset(&env);
	env.img_ptr = NULL;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	palette(&env);
	init_tabs(&env);
	trace_fdf(&env);
	mlx_hook(env.win, 2, 1L << 0, key_press, &env);
	mlx_hook(env.win, 3, 1L << 1, key_release, &env);
	mlx_hook(env.win, 17, 1L << 17, close_program, &env);
	mlx_loop_hook(env.mlx, key_funct, &env);
	mlx_loop(env.mlx);
	return (0);
}
