/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:59:30 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/08 12:24:29 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb > 1 && nb < 13)
	{
		result = result * ft_recursive_factorial(nb - 1);
		return (result);
	}
	if (nb == 1 || nb == 0)
		return (1);
	else
		return (0);
}
