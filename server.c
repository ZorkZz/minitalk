/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:41:01 by astachni          #+#    #+#             */
/*   Updated: 2023/03/07 01:50:35 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

int	value;

void	signal_handler(int sign)
{

	if (sign == 10)
		value = (value << 1) | 0;
	else if (sign == 12)
		value = (value << 1) | 1;
	ft_putnbr_base(value, "01");
	ft_printf("\n");
	ft_printf("%d\n", value);
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	new_handler;

	pid = getpid();
	value = 0;
	ft_printf("%d\n", pid);
	new_handler.sa_handler = signal_handler;
	// sigaction(SIGUSR1, &new_handler, NULL);
	// sigaction(SIGUSR2, &new_handler, NULL);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
