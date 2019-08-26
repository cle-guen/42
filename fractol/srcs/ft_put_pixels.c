/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:15:50 by cle-guen          #+#    #+#             */
/*   Updated: 2018/03/20 18:19:07 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixels(t_env *e, int x, int y, int color)
{
	if (x < 0 || x >= WIN_W_M || y >= WIN_H)
		return ;
	*((int *)&e->data[(e->oct_p_pix * x) + (e->size_line * y)]) = color;
}
