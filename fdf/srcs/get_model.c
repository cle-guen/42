/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_model.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:56:52 by cle-guen          #+#    #+#             */
/*   Updated: 2018/02/13 17:04:44 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_all(t_env *env, char **split, char *line)
{
	int	j;

	j = -1;
	while (++j < env->width_map)
		free(split[j]);
	free(env->map);
	free(line);
	free(split);
}

static int	parse(t_env *env, int fd, int i, int j)
{
	char	*line;
	char	**split;
	int		**tmp;

	env->map = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		env->height_map++;
		env->width_map = count(line);
		split = ft_strsplit(line, ' ');
		if (!(tmp = (int**)malloc(sizeof(int*) * env->height_map)))
			return (0);
		i = -1;
		while (++i < env->height_map - 1)
			tmp[i] = env->map[i];
		if (!(tmp[i] = (int*)malloc(sizeof(int) * env->width_map)))
			return (0);
		j = -1;
		while (++j < env->width_map)
			tmp[i][j] = check_digit(split[j]);
		free_all(env, split, line);
		env->map = tmp;
	}
	return (1);
}

static void	get_min_a_max(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	env->int_min = env->map[0][0];
	env->int_max = env->map[0][0];
	while (++i < env->height_map)
	{
		j = -1;
		while (++j < env->width_map)
		{
			if (env->map[i][j] < env->int_min)
				env->int_min = env->map[i][j];
			if (env->map[i][j] > env->int_max)
				env->int_max = env->map[i][j];
		}
	}
}

static void	to_zero(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->height_map)
	{
		j = -1;
		while (++j < env->width_map)
		{
			if (env->int_min < 0)
				env->map[i][j] = env->map[i][j] + abs(env->int_min);
			if (env->int_min > 0)
				env->map[i][j] = env->map[i][j] - abs(env->int_min);
		}
	}
}

int			get_model(t_env *env, char *file)
{
	int		fd;

	env->width_map = 0;
	env->height_map = 0;
	if ((fd = open(file, O_RDONLY)) < 0 || read(fd, env->buff, 0) < 0)
		not_valid();
	if (!parse(env, fd, 0, 0))
		return (0);
	if (env->height_map <= 1 && env->width_map <= 1)
		not_valid();
	get_min_a_max(env);
	if (env->int_min != 0)
		to_zero(env);
	env->int_max -= env->int_min;
	env->int_min = 0;
	close(fd);
	return (1);
}
