/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:07:03 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/29 17:28:34 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int pwr;
	int tmp;

	tmp = n;
	if ((pwr = n < 0 ? -1 : 1) == -1)
		ft_putchar_fd('-', fd);
	while (tmp /= 10)
		pwr *= 10;
	while (pwr)
	{
		ft_putchar_fd((n / pwr) + '0', fd);
		n -= (n / pwr) * pwr;
		pwr /= 10;
	}
}
