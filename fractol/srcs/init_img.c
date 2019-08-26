/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:37:35 by cle-guen          #+#    #+#             */
/*   Updated: 2018/03/20 18:19:22 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_img(t_env *e)
{
	if (e->img_ptr)
		mlx_destroy_image(e->mlx, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx, WIN_W_M, WIN_H);
	e->data = mlx_get_data_addr(e->img_ptr, &e->b_p_pix
			, &e->size_line, &e->endian);
	e->oct_p_pix = e->b_p_pix / 8;
	mlx_clear_window(e->mlx, e->win);
}
