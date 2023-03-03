/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:08:42 by astachni          #+#    #+#             */
/*   Updated: 2023/03/03 16:05:53 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

int	main(int ac, char **av)
{
	kill(ft_atoi(av[1]), getpid());
	sleep(1);
	kill(ft_atoi(av[1]), SIGUSR1);
	return (0);
}
