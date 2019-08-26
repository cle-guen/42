/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:36:42 by cle-guen          #+#    #+#             */
/*   Updated: 2017/12/04 12:47:30 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recprint(long nb, char *tab)
{
	if (nb >= 16)
		ft_recprint(nb / 16, tab);
	ft_putchar(tab[nb % 16]);
}

void		ft_putaddress(void *ptr)
{
	char	*tab;
	long	nb;

	tab = ft_strdup("0123456789abcdef");
	nb = (long)ptr;
	ft_putstr("0x");
	ft_recprint(nb, tab);
	free(tab);
}
