/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 10:48:21 by cle-guen          #+#    #+#             */
/*   Updated: 2018/04/16 18:44:30 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	tab_type(t_env *e)
{
	e->t_ter[MANDELBROT] = "      [MANDELBROT]";
	e->t_ter[JULIA] = "        [JULIA]";
	e->t_ter[BURNINGSHIP] = "     [BURNINGSHIP]";
	e->t_ter[TRICORN] = "       [TRICORN]";
	e->t_ter[EYE] = "         [EYE]";
	e->t_ter[CELTIC] = "        [CELTIC]";
}

static void	tab_help(t_env *e)
{
	char	*tmp;

	e->tab[0] = e->t_ter[e->type];
	tmp = ft_itoa(e->iter);
	e->tab[1] = "------------------------";
	e->tab[2] = " ";
	e->tab[3] = ft_strjoin("       ITER : ", tmp);
	free(tmp);
	tmp = ft_itoa(e->mouse_x);
	e->tab[4] = ft_strjoin("       X : ", tmp);
	free(tmp);
	tmp = ft_itoa(e->mouse_y);
	e->tab[5] = ft_strjoin("       Y : ", tmp);
	free(tmp);
	e->tab[6] = " ";
	e->tab[7] = "------------------------";
	e->tab[8] = " ";
	e->tab[9] = "    PRESS H FOR HELP";
}

static void	tab_help_bis(t_env *e)
{
	e->t_bis[0] = "    PRESS H FOR HOME";
	e->t_bis[1] = "------------------------";
	e->t_bis[2] = "[1]     | MANDELBROT";
	e->t_bis[3] = "[2]     | JULIA";
	e->t_bis[4] = "[3]     | BURNINGSHIP";
	e->t_bis[5] = "[4]     | TRICORN";
	e->t_bis[6] = "[5]     | EYE";
	e->t_bis[7] = "[6]     | CELTIC";
	e->t_bis[8] = "[UP]    | MOVE UP";
	e->t_bis[9] = "[DOWN]  | MOVE DOWN";
	e->t_bis[10] = "[LEFT]  | MOVE LEFT";
	e->t_bis[11] = "[RIGHT] | MOVE RIGHT";
	e->t_bis[12] = "[+]     | INCREASE ITER";
	e->t_bis[13] = "[-]     | DECREASE ITER";
	e->t_bis[14] = "[>]     | NEXT THEME";
	e->t_bis[15] = "[<]     | PREV THEME";
	e->t_bis[16] = "[DEL]   | RESET FRACTAL";
	e->t_bis[17] = "[SPACE] | PAUSE";
}

void		help(t_env *e)
{
	int	i;

	i = -1;
	tab_type(e);
	tab_help(e);
	tab_help_bis(e);
	if (e->state[H_KEY] == 1)
		while (++i < 18)
		{
			if (e->type != JULIA && i == 17)
				break ;
			mlx_string_put(e->mlx, e->win, WIN_W + 8, 22 * i
					, WHITE * (e->theme % 2 == 0), e->t_bis[i]);
		}
	else if (e->state[H_KEY] == 0)
	{
		while (++i < 10)
			mlx_string_put(e->mlx, e->win, WIN_W + 8, 22 * i
					, WHITE * (e->theme % 2 == 0), e->tab[i]);
	}
	i = 3;
	while (i <= 5)
		free(e->tab[i++]);
}
