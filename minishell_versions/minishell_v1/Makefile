# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 18:28:06 by imounjed          #+#    #+#              #
#    Updated: 2024/08/29 16:22:28 by lkhalifa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
INC = include -I ./libft/
SRCS = src/main.c src/parsing/parsing.c src/parsing/lexing.c src/parsing/infos.c src/errors/free.c src/execution/create_fd.c src/execution/execution.c src/env/env.c \
		src/builtin/pwd.c src/builtin/utils.c src/builtin/echo.c src/parsing/show.c src/builtin/env.c src/builtin/export.c src/builtin/unset.c src/builtin/cd.c \
		src/builtin/exit.c src/parsing/create_commands.c src/parsing/modify_commands.c src/parsing/modify_commands2.c src/free/free_infos.c \
		src/free/free_create_commands.c \
		src/tokenizer/token_operators.c src/tokenizer/token_utils.c src/tokenizer/token_values.c src/tokenizer/tokens.c src/tokenizer/token_check.c \
		src/signals.c src/errors/error.c



OBJS = $(SRCS:.c=.o)

CC = cc

all : libft.a $(NAME)


libft.a :
	make -C ./libft
	mv libft/libft.a ./


$(NAME) : $(OBJS)
	$(CC) -g -o $(NAME) $(OBJS) -lreadline libft.a 


%.o: %.c
#	$(CC) -I $(INC) -c $< -o $@  -lreadline
	$(CC) -g -I $(INC) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm libft.a

re: fclean all

cc :
	clear && make re && ./minishell

vv :
	clear && make re && valgrind ./minishell

.PHONY: all clean fclean re bonus