/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:10:39 by cle-guen          #+#    #+#             */
/*   Updated: 2018/03/30 19:03:05 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr(USAGE);
	ft_putstr(ARG);
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc != 2)
	{
		usage();
		return (0);
	}
	if (parse(&e, argv[1]) != 1)
		return (0);
	e.str_fract = argv[1];
	window(&e);
	tab_color(&e);
	mlx_hook(e.win, 2, 1L << 0, key_press, &e);
	mlx_hook(e.win, 3, 1L << 1, key_release, &e);
	mlx_hook(e.win, 4, 1L << 2, mouse_press, &e);
	mlx_hook(e.win, 5, 1L << 3, mouse_release, &e);
	mlx_hook(e.win, 6, 1L << 6, mouse_move, &e);
	mlx_hook(e.win, 17, 1L << 17, close_program, &e);
	mlx_loop_hook(e.mlx, ft_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
