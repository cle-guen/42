/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:32:58 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/29 17:28:19 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbrl(long nb)
{
	long	pwr;
	long	tmp;

	tmp = nb;
	if ((pwr = nb < 0 ? -1 : 1) == -1)
		ft_putchar('-');
	while (tmp /= 10)
		pwr *= 10;
	while (pwr)
	{
		ft_putchar((nb / pwr) + '0');
		nb -= (nb / pwr) * pwr;
		pwr /= 10;
	}
}
