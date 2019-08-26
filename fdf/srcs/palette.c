/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:45:08 by cle-guen          #+#    #+#             */
/*   Updated: 2018/01/30 15:30:56 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	palette(t_env *env)
{
	env->palette[0] = 0x000C3748;
	env->palette[1] = 0x0060FFFA;
	env->palette[2] = 0x00581845;
	env->palette[3] = 0x00F9834C;
	env->palette[4] = 0x004F3401;
	env->palette[5] = 0x00A8E96F;
	env->palette[6] = 0x00231F1F;
	env->palette[7] = 0x00BE0000;
	env->palette[8] = 0x0031312E;
	env->palette[9] = 0x00C3BDBD;
}
