/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:41:01 by astachni          #+#    #+#             */
/*   Updated: 2023/03/08 16:40:14 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

int	value[16], nb_bit;

void	signal_handler(int sign)
{

	if (sign == 10)
		value[nb_bit] = 0;
	else if (sign == 12)
		value[nb_bit] = 1;
}

int	main(void)
{
	__pid_t	pid;
	int		to_write;
	struct sigaction	new_handler;

	pid = getpid();
	nb_bit = 0;
	ft_printf("%d\n", pid);
	new_handler.sa_handler = signal_handler;
	// sigaction(SIGUSR1, &new_handler, NULL);
	// sigaction(SIGUSR2, &new_handler, NULL);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (nb_bit < 16)
	{
		pause();
		nb_bit++;
		if (nb_bit == 16)
		{
			to_write = 0;
			nb_bit--;
			while (nb_bit >= 0)
			{
				if (value[nb_bit] == 0)
					to_write = (to_write << 1) | 0;
				else
					to_write = (to_write << 1) | 1;
				nb_bit--;
			}
			ft_printf("%c", to_write);
			//ft_putnbr_base(to_write, "01");
			nb_bit = 0;
			ft_bzero(value, 17);
		}
	}
	return (0);
}
