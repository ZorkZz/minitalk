/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:43:07 by astachni          #+#    #+#             */
/*   Updated: 2023/04/10 15:19:19 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libs/libft/libft.h"
# include <signal.h>

int	g_value_bit;

char	*add_char(char *str, int nb_bit, int *tab_bit, int client_pid);
int		*reset_buffer(int *tab_bit);

#endif