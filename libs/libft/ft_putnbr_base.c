/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:28:18 by astachni          #+#    #+#             */
/*   Updated: 2023/03/06 19:14:12 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

unsigned int	base_converter(char *base)
{
	unsigned int	i0;
	unsigned int	i1;

	i0 = 0;
	while (base[i0] != '\0')
	{
		i1 = i0 + 1;
		while (base[i1] != '\0')
		{
			if (base [i0] == '+' || base[i1] == '-')
				return (0);
			if (base[i0] == base [i1])
			{
				return (0);
			}
			i1 ++;
		}
		i0++;
	}
	return (i0);
}

void	ft_recursive(unsigned int nbr, char *base, unsigned int base_nbr)
{
	if (nbr < base_nbr)
	{
		ft_putchar(base[nbr]);
	}
	else
	{
		ft_recursive(nbr / base_nbr, base, base_nbr);
		ft_putchar(base[nbr % base_nbr]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_nbr;
	unsigned int	nbr_u;

	base_nbr = base_converter(base);
	if (base_nbr == 0)
		return ;
	else if (base_nbr == 1)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr_u = nbr * -1;
	}
	else
		nbr_u = nbr;
	ft_recursive(nbr_u, base, base_nbr);
}
