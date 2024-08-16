# ------------  COLORS  ----------------------------------------------------- #
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
DEFAULT			=	\033[0m

# ------------  FILES  ----------------------------------------------------- #
NAME			=	megaphone
SRC				=	megaphone.cpp
OBJ				=	$(SRC:.cpp=.o)

# ------------  COMMANDS  ------------------------------------------------------- #
CC				=	c++
RM				=	rm -f
CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98

# ------------  RULES  ------------------------------------------------------- #
all:				${NAME}

$(NAME):			$(OBJ)
					@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
					@echo "$(GREEN)Compiled $(NAME)$(DEFAULT)"

%.o: %.cpp
					@$(CC) $(CPPFLAGS) -c $< -o $@

clean:	
					@$(RM) $(OBJ)
					@echo "$(YELLOW)Cleaned $(OBJ)$(DEFAULT)"

fclean:				clean
					@$(RM) $(NAME)
					@echo "$(RED)Cleaned $(NAME)$(DEFAULT)"

re:					fclean all

.PHONY: 			all clean fclean re