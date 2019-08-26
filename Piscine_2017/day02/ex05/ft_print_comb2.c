/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:03:14 by cle-guen          #+#    #+#             */
/*   Updated: 2017/07/08 11:26:44 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	numbers(int i, int k)
{
	ft_putchar(i / 10 + '0');
	ft_putchar(i % 10 + '0');
	ft_putchar(' ');
	ft_putchar(k / 10 + '0');
	ft_putchar(k % 10 + '0');
	if (i != 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int i;
	int k;

	i = 0;
	while (i <= 98)
	{
		k = i + 1;
		while (k <= 99)
		{
			numbers(i, k);
			k++;
		}
		i++;
	}
}
