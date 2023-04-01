# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 15:00:51 by astachni          #+#    #+#              #
#    Updated: 2023/04/01 22:42:09 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client

NAME_SERVER = server

SRCS_SERVER = server.c server_utils.c

SRC_CLIENT = client.c

OBJS_DIR = objs/

OBJS_SERVER = $(SRCS_SERVER:%.c=$(OBJS_DIR)%.o)

OBJS_CLIENT = $(SRC_CLIENT:%.c=$(OBJS_DIR)%.o)

LIBS = libs/libft/libft.a

HEADER = header/minitalk.h

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: libft $(NAME_CLIENT) $(NAME_SERVER)

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C libs/libft bonus

$(NAME_CLIENT): $(LIBS) $(OBJS_CLIENT) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBS) -o $(NAME_CLIENT)

$(NAME_SERVER):	$(LIBS) $(OBJS_SERVER) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)
	@norminette

clean:
	make clean -C libs/libft
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all