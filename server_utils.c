/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:22:28 by astachni          #+#    #+#             */
/*   Updated: 2023/03/09 15:16:05 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

char	bin_to_char(int nb_bit, int *tab_bit, char *str);

char	*add_char(char *str, int nb_bit, int *tab_bit)
{
	int		i;
	char	c;
	char	*new_str;

	c = 0;
	i = 0;
	c = bin_to_char(nb_bit, tab_bit, str);
	new_str = malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	if (str != NULL)
	{
		while (str[i])
		{
			new_str[i] = str[i];
			i++;
		}
		free(str);
	}
	new_str[i] = c;
	new_str[i + 1] = 0;
	if (c == 0)
		return (free(new_str), NULL);
	return (new_str);
}

char	bin_to_char(int nb_bit, int *tab_bit, char *str)
{
	char	to_write;

	to_write = 0;
	nb_bit--;
	while (nb_bit >= 0)
	{
		if (tab_bit[nb_bit] == 0)
			to_write = (to_write << 1) | 0;
		else
			to_write = (to_write << 1) | 1;
		nb_bit--;
	}
	reset_buffer(tab_bit);
	if (to_write == 0)
		ft_printf("%s\n", str);
	return (to_write);
}

int	*reset_buffer(int *tab_bit)
{
	int	i;

	i = 0;
	while (i < 16)
		tab_bit[i++] = 0;
	return (tab_bit);
}
