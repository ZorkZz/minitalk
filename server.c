/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:41:01 by astachni          #+#    #+#             */
/*   Updated: 2023/04/05 19:29:04 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

void	signal_handler(int sign, siginfo_t *info, void	*context);

int	g_value_bit;

int	main(void)
{
	int					nb_bit;
	int					tab_bit[8];
	char				*str;
	struct sigaction	sa;

	nb_bit = 0;
	ft_printf("PID:\t%d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (nb_bit < 8)
	{
		pause();
		tab_bit[nb_bit++] = g_value_bit;
		g_value_bit = 0;
		if (nb_bit == 8)
		{
			str = add_char(str, nb_bit, tab_bit);
			nb_bit = 0;
		}
	}
	return (0);
}

void	signal_handler(int sign, siginfo_t *info, void	*context)
{
	(void)context;
	if (sign == SIGUSR1)
		g_value_bit = 0;
	else if (sign == SIGUSR2)
		g_value_bit = 1;
	else
	{
		ft_putstr_fd("Error \n", 2);
		exit(1);
	}
	kill(info->si_pid, SIGUSR1);
}
