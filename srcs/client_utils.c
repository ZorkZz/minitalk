/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:49:19 by astachni          #+#    #+#             */
/*   Updated: 2023/04/11 13:35:38 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk_client.h"

extern int	g_bit_recive;

void	wait(void)
{
	int	time;

	time = 0;
	if (g_bit_recive == 1)
	{
		g_bit_recive = 0;
		return ;
	}
	while (time < 2000000)
	{
		if (g_bit_recive == 1)
		{
			g_bit_recive = 0;
			return ;
		}
		usleep(10);
		time += 10;
	}
	ft_putstr_fd("ERROR SERVER \n", 2);
	exit(1);
}
