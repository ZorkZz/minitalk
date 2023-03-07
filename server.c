/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:41:01 by astachni          #+#    #+#             */
/*   Updated: 2023/03/07 15:36:16 by astachni         ###   ########.fr       */
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

int	reverse_signal(int	value)
{
	int	return_value;
	int	i;

	i = 0;
	return_value = 0;
	while (i < 10)
	{
		return_value |= ((value << i) & 1) << (15 - i);
	}
	ft_printf("%d\n", return_value);
	return (return_value);
}

int	main(void)
{
	__pid_t				pid;
	int					nb_bit;
	struct sigaction	new_handler;

	pid = getpid();
	value = 0;
	nb_bit = 0;
	ft_printf("%d\n", pid);
	new_handler.sa_handler = signal_handler;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	while (1)
	{
		pause();
		nb_bit++;
		ft_printf("%d\n", nb_bit);
		if (nb_bit == 15)
			reverse_signal(value);
	}
	return (0);
}
