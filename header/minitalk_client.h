/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:49:37 by astachni          #+#    #+#             */
/*   Updated: 2023/04/11 15:12:19 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H

# define MINITALK_CLIENT_H

# include "../libs/libft/libft.h"
# include <signal.h>

void	condition_to_send(int pid, int ac, char **av);
void	send_bits(unsigned char c, int pid, int i);
void	kill_bit(unsigned char c, int shift, int pid);
void	handler(int sign);
void	wait(void);

#endif