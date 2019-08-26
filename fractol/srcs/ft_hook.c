/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:56:30 by cle-guen          #+#    #+#             */
/*   Updated: 2018/03/20 18:29:02 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_hook(t_env *e)
{
	init_img(e);
	info(e);
	input_funct(e);
	mouse_funct(e);
	mlx_clear_window(e->mlx, e->win);
	multi_thread(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	help(e);
	return (0);
}
