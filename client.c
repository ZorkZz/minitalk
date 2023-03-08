/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:08:42 by astachni          #+#    #+#             */
/*   Updated: 2023/03/08 15:51:51 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	count;
	int	w;

	if (ac == 3)
	{
		i = 0;
		count = 0;
		w = 0;
		pid = ft_atoi(av[1]);
		while (av[2][w])
		{
			while (count < 16)
			{
				if ((av[2][w] >> i) != 0)
				{
					if ((av[2][w] >> i) % 2 == 0)
						kill(pid, SIGUSR1);
					else if ((av[2][w] >> i) % 2 == 1)
						kill(pid, SIGUSR2);
					i++;
				}
				else if ((av[2][w] >> i) == 0)
					kill(pid, SIGUSR1);
				count++;
				usleep(500);
			}
			i = 0;
			count = 0;
			w++;
		}
	}
	return (0);
}
