/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:41:01 by astachni          #+#    #+#             */
/*   Updated: 2023/03/09 00:27:11 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

void	signal_handler(int sign);
void	print_value(void);
void	reset_buffer(void);

int	g_value[16];
int	g_nb_bit;

int	main(void)
{
	__pid_t				pid;
	struct sigaction	new_handler;

	pid = getpid();
	g_nb_bit = 0;
	ft_printf("PID:\t%d\n", pid);
	reset_buffer();
	new_handler.sa_handler = signal_handler;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	while (g_nb_bit < 16)
	{
		pause();
		g_nb_bit++;
		if (g_nb_bit == 16)
			print_value();
	}
	return (0);
}

void	print_value(void)
{
	int	to_write;

	to_write = 0;
	g_nb_bit--;
	while (g_nb_bit >= 0)
	{
		if (g_value[g_nb_bit] == 0)
			to_write = (to_write << 1) | 0;
		else
			to_write = (to_write << 1) | 1;
		g_nb_bit--;
	}
	ft_printf("%c", to_write);
	reset_buffer();
	g_nb_bit = 0;
}

void	signal_handler(int sign)
{
	if (sign == 10)
		g_value[g_nb_bit] = 0;
	else if (sign == 12)
		g_value[g_nb_bit] = 1;
	else
	{
		ft_putstr_fd("Error \n", 2);
		exit(1);
	}
}

void	reset_buffer(void)
{
	int	i;

	i = 0;
	while (i < 16)
		g_value[i++] = 0;
}
