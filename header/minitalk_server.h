/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:43:07 by astachni          #+#    #+#             */
/*   Updated: 2023/04/11 15:17:16 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

# include "../libs/libft/libft.h"
# include <signal.h>

unsigned char	*add_char(unsigned char *str, int nb_bit, int *tab_bit,
					int client_pid);
int				*reset_buffer(int *tab_bit);
void			error(unsigned char *str, int client_pid);
unsigned char	bin_to_char(int nb_bit, int *tab_bit, unsigned char *str);

#endif