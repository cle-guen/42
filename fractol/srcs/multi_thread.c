/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:01:58 by cle-guen          #+#    #+#             */
/*   Updated: 2018/03/22 16:41:35 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	draw_thread(t_env *e, int thread, double xt_min)
{
	calc_fract(e, thread, xt_min);
}

static void	*calcul_thread(void *arg)
{
	t_pointer	*p;
	double		tmp;
	double		xt_min;

	p = (t_pointer *)arg;
	tmp = (p->e_th->x_max - p->e_th->x_min) / THREAD;
	xt_min = p->e_th->x_min + (tmp * p->thread);
	draw_thread(p->e_th, p->thread, xt_min);
	return (0);
}

int			multi_thread(t_env *e)
{
	pthread_t	th[THREAD];
	t_pointer	p[THREAD];
	int			i;

	i = 0;
	while (i < THREAD)
	{
		p[i].thread = i;
		p[i].e_th = e;
		if (pthread_create(&th[i], NULL, calcul_thread, &p[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < THREAD)
		if (pthread_join(th[i++], NULL))
			close_program(e);
	return (0);
}
