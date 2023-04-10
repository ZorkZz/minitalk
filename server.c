/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:41:01 by astachni          #+#    #+#             */
/*   Updated: 2023/04/10 16:50:11 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

void	signal_handler(int sign, siginfo_t *info, void	*context);

int	main(void)
{
	struct sigaction	sa;
	sigset_t			mask;

	ft_printf("PID:\t%d\n", getpid());
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = mask;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

void	signal_handler(int sign, siginfo_t *info, void	*context)
{
	static int	client_pid = -1;
	static int	nb_bit = 0;
	static int	tab_bit[8];
	static char	*str = NULL;

	(void)context;
	if (client_pid != -1 && g_value_bit != -1 && client_pid != info->si_pid)
	{
		if (str)
			free(str);
		ft_putstr_fd("Error \n", 2);
		exit(1);
	}
	client_pid = info->si_pid;
	if (sign == SIGUSR1)
		g_value_bit = 0;
	else if (sign == SIGUSR2)
		g_value_bit = 1;
	tab_bit[nb_bit++] = g_value_bit;
	g_value_bit = 0;
	if (nb_bit == 8)
	{
		str = add_char(str, nb_bit, tab_bit, client_pid);
		nb_bit = 0;
	}
	kill(client_pid, SIGUSR1);
}
