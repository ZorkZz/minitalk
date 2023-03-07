/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:08:42 by astachni          #+#    #+#             */
/*   Updated: 2023/03/07 15:34:13 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

int	main(int ac, char **av)
{
	int	nb;
	int	cond;
	int	i;

	if (ac == 2)
	{
		i = 0;
		nb = ft_atoi(av[1]);
		cond = nb;
		while ((cond >> i) != 0)
		{
			if ((nb >> i) % 2 == 0)
				ft_printf("%d\n", kill(nb, SIGUSR1));
			else
				ft_printf("%d\n", kill(nb, SIGUSR2));
			i++;
			ft_printf("%d\n", cond >> i);
			ft_printf("%d\n", (cond >> i));
			i++;
			sleep(1);
		}
		ft_printf("\n");
		ft_putnbr_base(ft_atoi(av[1]), "01");
	}
	return (0);
}
