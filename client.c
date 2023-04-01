/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:08:42 by astachni          #+#    #+#             */
/*   Updated: 2023/04/01 22:15:16 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

void	condition_to_send(int pid, int ac, char **av);
void	send_bits(char c, int pid);

int	main(int ac, char **av)
{
	int	pid;

	if (ac >= 3)
	{
		pid = ft_atoi(av[1]);
		condition_to_send(pid, ac, av);
	}
	else
		ft_printf("./client [PID] ['str to send']\n\n");
	return (0);
}

void	condition_to_send(int pid, int ac, char **av)
{
	int	i;
	int	j;

	i = 2;
	while (i < ac && av && av[i])
	{
		j = 0;
		while (av && av[i] && av[i][j])
		{
			send_bits(av[i][j], pid);
			j++;
			if (i < ac - 1 && av[i][j] == '\0')
			{
				send_bits(' ', pid);
			}
			usleep(50);
		}
		i++;
		usleep(50);
	}
	send_bits(0, pid);
}

void	send_bits(char c, int pid)
{
	int	count;
	int	shift;

	count = 0;
	shift = 0;
	while (count < 16)
	{	
		if ((c >> shift) != 0)
		{
			if ((c >> shift) % 2 == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else if ((c >> shift) % 2 == 1)
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
		}
		else
			kill(pid, SIGUSR1);
		count++;
		shift++;
		usleep(70);
	}
}
