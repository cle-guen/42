/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:53:19 by cle-guen          #+#    #+#             */
/*   Updated: 2018/02/13 15:29:13 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			init_tabs(t_env *env)
{
	int	i;

	i = 0;
	if (!(env->c_x = (int**)malloc(sizeof(int*) * env->height_map)))
		return (0);
	if (!(env->c_y = (int**)malloc(sizeof(int*) * env->height_map)))
		return (0);
	while (i < env->height_map)
	{
		if (!(env->c_x[i] = (int*)malloc(sizeof(int) * env->width_map)))
			return (0);
		if (!(env->c_y[i] = (int*)malloc(sizeof(int) * env->width_map)))
			return (0);
		i++;
	}
	return (1);
}

static void	init_draw(t_env *env, t_draw *point, int i, int j)
{
	point->x = env->c_x[i][j];
	point->y = env->c_y[i][j];
}

static void	trace_fdf_bis(t_env *env, int i, int j, t_draw *point)
{
	env->c_x[i][j] = (j * env->zoom * env->cos)
		- (i * env->zoom * env->sin) + env->origin_x;
	env->c_y[i][j] = (j * env->zoom * env->sin)
		+ (i * env->zoom * env->cos) + env->origin_y
		- ((env->map[i][j] * env->zoom) / env->scale);
	init_draw(env, point, i, j);
	env->color[1] = ft_color((float)env->map[i][j] / env->int_max
			, env->palette[env->theme], env->palette[env->theme + 1]);
	if (j > 0 && (env->map[i][j] >= env->level
				|| env->map[i][j - 1] >= env->level))
	{
		env->color[0] = ft_color((float)env->map[i][j - 1]
				/ env->int_max, env->palette[env->theme]
				, env->palette[env->theme + 1]);
		draw_line(env, env->c_x[i][j - 1], env->c_y[i][j - 1], *point);
	}
	if (i > 0 && (env->map[i][j] >= env->level
				|| env->map[i - 1][j] >= env->level))
	{
		env->color[0] = ft_color((float)env->map[i - 1][j]
				/ env->int_max, env->palette[env->theme]
				, env->palette[env->theme + 1]);
		draw_line(env, env->c_x[i - 1][j], env->c_y[i - 1][j], *point);
	}
}

void		trace_fdf(t_env *env)
{
	int		i;
	int		j;
	t_draw	point;

	if (env->img_ptr)
		mlx_destroy_image(env->mlx, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->buff = mlx_get_data_addr(env->img_ptr, &env->b_p_pix
			, &env->size_line, &env->endian);
	env->oct_p_pix = env->b_p_pix / 8;
	mlx_clear_window(env->mlx, env->win);
	i = -1;
	while (++i < env->height_map)
	{
		j = -1;
		while (++j < env->width_map)
			trace_fdf_bis(env, i, j, &point);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img_ptr, 0, 0);
}
