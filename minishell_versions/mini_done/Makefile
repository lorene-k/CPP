# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 18:28:06 by imounjed          #+#    #+#              #
#    Updated: 2024/09/19 15:39:00 by lkhalifa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
INC = include -I ./libft/
SRCS = src/main.c src/parsing/parsing.c src/errors/free.c src/execution/create_fd.c src/execution/execution.c \
		src/builtin/pwd.c src/builtin/utils.c src/builtin/echo.c src/builtin/env.c src/builtin/export.c src/builtin/unset.c src/builtin/cd.c \
		src/builtin/exit.c src/parsing/create_commands.c src/parsing/create_commands_utils.c src/parsing/modify_commands.c src/parsing/modify_commands2.c src/free/free_infos.c \
		src/free/free_create_commands.c \
		src/tokenizer/token_nodes.c src/tokenizer/token_operators.c src/tokenizer/token_utils.c src/tokenizer/token_values.c src/tokenizer/tokens.c src/tokenizer/token_check.c \
		src/signals/signals.c src/signals/signals_heredoc.c src/errors/error.c \
		src/env/env2.c src/env/env3.c src/env/new_env.c src/env/exp_check.c src/parsing/check_redirects.c \
		src/parsing/modify_commands3.c src/parsing/remove_quotes.c src/execution/create_pipes.c src/execution/child.c \
		src/parsing/init_cmds.c src/parsing/handle_heredoc.c src/parsing/parsing_infos.c src/env/new_env2.c src/env/env2_2.c \
		src/builtin/export_2.c src/builtin/export_3.c src/parsing/modify_commands4.c src/parsing/modify_commands5.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : libft.a $(NAME)


libft.a :
	make -C ./libft
	mv libft/libft.a ./


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) -lreadline libft.a 


%.o: %.c
	# $(CC) $(CFLAGS) -g -I $(INC) -c $< -o $@
	$(CC) -g -I $(INC) $(CFLAGS) -c $< -o $@

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