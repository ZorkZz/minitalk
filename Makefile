# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 15:00:51 by astachni          #+#    #+#              #
#    Updated: 2023/04/11 13:57:58 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client

NAME_SERVER = server

SRCS_SERVER = srcs/server.c srcs/server_utils.c

SRC_CLIENT = srcs/client.c srcs/client_utils.c

OBJS_DIR = objs/

OBJS_SERVER = $(SRCS_SERVER:%.c=$(OBJS_DIR)%.o)

OBJS_CLIENT = $(SRC_CLIENT:%.c=$(OBJS_DIR)%.o)

LIBS = libs/libft/libft.a

HEADER = header/minitalk_server.h header/minitalk_client.h

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: libft $(NAME_CLIENT) $(NAME_SERVER)

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make -C libs/libft

$(NAME_CLIENT): $(LIBS) $(OBJS_CLIENT) header/minitalk_client.h Makefile
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBS) -o $(NAME_CLIENT)

$(NAME_SERVER):	$(LIBS) $(OBJS_SERVER) header/minitalk_server.h Makefile
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)

norm:
	@norminette | grep Error!

clean:
	make clean -C libs/libft
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)

fclean: clean
	make fclean -C libs/libft
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all