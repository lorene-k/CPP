# ------------  COLORS  ----------------------------------------------------- #
RED				=	\\033[0;31m
GREEN			=	\\033[0;32m
YELLOW			=	\\033[0;33m
DEFAULT			=	\\033[0m

# ------------  PROJECT  ---------------------------------------------------- #
NAME			=	fragtrap

# ------------  DIRECTORIES  ------------------------------------------------ #
SRC_DIR			=	srcs/
INC_DIR			= 	includes/
OBJ_DIR			=	objs/

# ------------  SOURCES  ---------------------------------------------------- #
SRC_FLS			=	main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp \
					FragTrap.cpp

# ------------  FILEPATHS  -------------------------------------------------- #
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FLS))
OBJS			=	$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o, $(SRCS))

# ------------  FLAGS  ------------------------------------------------------ #
RM_FLAGS		=	-rf
CPP_FLAGS		=	-Wall -Wextra -Werror -std=c++98 -g
INCLUDES		=	-I$(INC_DIR)

# ------------  COMMANDS  --------------------------------------------------- #
CC				=	c++
RM				=	rm $(RM_FLAGS)

# ------------  RULES  ------------------------------------------------------ #
all:				${NAME}

$(NAME):			$(OBJS)
					@$(CC) $(CPP_FLAGS) -o $(NAME) $(OBJS)
					@echo "$(GREEN)Compiled $(NAME)$(DEFAULT)"

$(OBJ_DIR)%.o:		$(SRC_DIR)%.cpp
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CPP_FLAGS) $(INCLUDES) -c $< -o $@

clean:	
					@$(RM) $(OBJ_DIR)
					@echo "$(YELLOW)Cleaned $(OBJS)$(DEFAULT)"

fclean:				clean
					@$(RM) $(NAME)
					@echo "$(RED)Cleaned $(NAME)$(DEFAULT)"

re:					fclean all

.PHONY: 			all clean fclean re