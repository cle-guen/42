/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:24:02 by cle-guen          #+#    #+#             */
/*   Updated: 2018/06/01 15:08:36 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_len(uintmax_t n, int base)
{
	int	len;

	len = 1;
	while (n >= (uintmax_t)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*pf_itoa_base(t_flags *flags, uintmax_t n, char *ba, int base)
{
	char	*str;
	int		len;

	(void)flags;
	len = set_len(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (len > -1)
	{
		str[len] = ba[n % base];
		len--;
		n = n / base;
	}
	return (str);
}
