/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:43:07 by astachni          #+#    #+#             */
/*   Updated: 2023/04/06 20:15:58 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef D_XOPEN_SOURCE
#  define D_XOPEN_SOURCE 700
# endif

# include "../libs/libft/libft.h"
# include <signal.h>

char	*add_char(char *str, int nb_bit, int *tab_bit);
int		*reset_buffer(int *tab_bit);

#endif