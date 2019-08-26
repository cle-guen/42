/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:27:18 by cle-guen          #+#    #+#             */
/*   Updated: 2017/11/07 14:59:50 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	start;
	int		i;

	start = 'a';
	i = start;
	while (i <= 'z')
	{
		ft_putchar(i);
		i++;
	}
}
