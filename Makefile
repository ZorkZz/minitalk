# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 15:00:51 by astachni          #+#    #+#              #
#    Updated: 2023/03/09 14:41:17 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client

NAME_SERVER = server

SRCS_SERVER = server.c server_utils.c

OBJS_DIR = objs/

OBJS_SERVER = $(SRCS_SERVER:%.c=$(OBJS_DIR)%.o)

LIBS = libs/libft/libft.a

HEADER = header/minitalk.h

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: libft $(NAME_CLIENT) $(NAME_SERVER)

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C libs/libft bonus

$(NAME_CLIENT):	$(LIBS) $(HEADER) Makefile
	$(CC) -g3 $(CFLAGS) client.c $(LIBS) -o $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SERVER) $(LIBS) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)
	@norminette

clean:
	make clean -C libs/libft
	$(RM) $(OBJS_SERVER)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: clean all