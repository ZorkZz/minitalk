/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:41:01 by astachni          #+#    #+#             */
/*   Updated: 2023/03/09 15:11:19 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

void	signal_handler(int sign);

int	g_value_bit;

int	main(void)
{
	int					nb_bit;
	int					tab_bit[16];
	char				*str;
	struct sigaction	new_handler;

	nb_bit = 0;
	str = NULL;
	ft_printf("PID:\t%d\n", getpid());
	reset_buffer(tab_bit);
	new_handler.sa_handler = signal_handler;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	while (nb_bit < 16)
	{
		pause();
		tab_bit[nb_bit++] = g_value_bit;
		g_value_bit = 0;
		if (nb_bit == 16)
		{
			str = add_char(str, nb_bit, tab_bit);
			nb_bit = 0;
		}
	}
	return (0);
}

void	signal_handler(int sign)
{
	if (sign == SIGUSR1)
		g_value_bit = 0;
	else if (sign == SIGUSR2)
		g_value_bit = 1;
	else
	{
		ft_putstr_fd("Error \n", 2);
		exit(1);
	}
}
