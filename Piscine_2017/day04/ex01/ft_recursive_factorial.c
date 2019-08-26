/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:42:36 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/12 17:44:46 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int result;

	result = nb;
	if (nb > 1 && nb < 13)
	{
		result = result * ft_recursive_factorial(nb - 1);
		return (result);
	}
	else if (nb == 0 || nb == 1)
		return (1);
	else
		return (0);
}
