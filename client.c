/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:08:42 by astachni          #+#    #+#             */
/*   Updated: 2023/04/10 18:51:31 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk_client.h"

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, handler);
	g_bit_recive = 1;
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
			send_bits(av[i][j], pid, i);
			j++;
			if (i < ac - 1 && av[i][j] == '\0')
				send_bits(' ', pid, i);
		}
		i++;
	}
	send_bits(0, pid, i);
	ft_printf("\033[38;5;213mmessage envoye\n\033[0m");
}

void	send_bits(char c, int pid, int i)
{
	int					count;
	int					shift;

	count = 0;
	shift = 0;
	(void)i;
	while (count < 8)
	{
		wait();
		kill_bit(c, shift, pid);
		count++;
		shift++;
	}
}

void	kill_bit(char c, int shift, int pid)
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
	usleep(100);
}

void	handler(int sign)
{
	if (sign != SIGUSR1)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	g_bit_recive = 1;
}
