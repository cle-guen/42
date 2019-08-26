/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:48:53 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/21 16:56:06 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_neg(long *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	else
		return (0);
}

static int	set_len(long n, int neg)
{
	long	pwr;
	int		len;

	pwr = 1;
	len = 1 + neg;
	while (pwr * 10 <= n)
	{
		pwr *= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		neg;
	int		len;

	nb = (long)n;
	neg = set_neg(&nb);
	len = set_len(nb, neg);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	len--;
	if (neg == 1)
		str[0] = '-';
	while (len >= neg)
	{
		str[len] = (nb % 10) + 48;
		len--;
		nb = nb / 10;
	}
	return (str);
}
