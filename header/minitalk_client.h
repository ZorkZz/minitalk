/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:49:37 by astachni          #+#    #+#             */
/*   Updated: 2023/04/11 00:25:49 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H

# define MINITALK_CLIENT_H

# include "../libs/libft/libft.h"
# include <signal.h>

void	condition_to_send(int pid, int ac, char **av);
void	send_bits(char c, int pid, int i);
void	kill_bit(char c, int shift, int pid);
void	handler(int sign);
void	wait(void);

#endif