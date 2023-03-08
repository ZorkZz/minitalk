# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 15:00:51 by astachni          #+#    #+#              #
#    Updated: 2023/03/09 00:12:35 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client

NAME_SERVER = server

LIBS = libs/libft/libft.a

HEADER = header/minitalk.h

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: libft $(NAME_CLIENT) $(NAME_SERVER)

libft:
	$(MAKE) -C libs/libft bonus

$(NAME_CLIENT):	$(LIBS) $(HEADER) Makefile
	$(CC) -g3 $(CFLAGS) client.c $(LIBS) -o $(NAME_CLIENT)
	@norminette

$(NAME_SERVER):	$(LIBS) $(HEADER) Makefile
	$(CC) -g3 $(CFLAGS) server.c $(LIBS) -o $(NAME_SERVER)

clean:
	make fclean -C libs/libft
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: clean all