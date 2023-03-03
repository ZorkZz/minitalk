/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:41:01 by astachni          #+#    #+#             */
/*   Updated: 2023/03/03 16:04:33 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

void	signal_handler(int sign)
{
	ft_printf("\nsignal recu\n");
}

int	main(void)
{
	__pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	struct	sigaction new_handler = 
	{
		.sa_handler = signal_handler
	};
	if (sigaction(SIGUSR1, &new_handler, NULL) < 0)
	{
		ft_printf("--%d--", sigaction(SIGUSR1, &new_handler, NULL));
	}
	while (1)
	{
		pause();
	}
	return (0);
}
