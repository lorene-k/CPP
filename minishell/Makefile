# ------------  COLORS  ----------------------------------------------------- #
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
DEFAULT			=	\033[0m

# ------------  PROJECT  ----------------------------------------------------- #
NAME			=	minishell

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR			=	src/
INC_DIR			= 	includes/
OBJ_DIR			=	objs/
LFT_DIR			=	libft/

# ------------  SOURCES  ----------------------------------------------------- #
LFT				=	libft/libft.a

SRC_FLS			=	clear.c \
					lexer_types.c \
					lexer_values.c \
					lexer.c \
					loop.c \
					main.c \
					parse.c \
					tokens.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FLS))
OBJS			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SRCS))

# ------------  FLAGS  -------------------------------------------------------- #
CFLAGS			=	-Wall -Wextra -Werror -g
LFLAGS			=	-L./$(LFT_DIR) -lft
LIB_FLAGS		=	-lreadline -lncurses

MAKE_FLAGS		=	-s -C
RM_FLAGS		=	-rf

INCLUDES		=	-I/$(INC_DIR)

# ------------  COMMANDS  ------------------------------------------------------- #
CC				=	cc
MK				=	make all
MFC				=	make fclean
MC				=	make clean
RM				=	rm $(RM_FLAGS)

# ------------  RULES  ------------------------------------------------------- #
all:				${NAME}

$(NAME):			$(OBJS) $(LFT)
					@$(CC) $(CFLAGS) -o ./$(NAME) $(OBJS) $(LFLAGS) $(LIB_FLAGS)
					@echo "$(GREEN)Compiled $(NAME)$(DEFAULT)"

$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

$(LFT):
					@$(MK) $(MAKE_FLAGS) $(LFT_DIR)

clean:	
					@$(RM) $(OBJ_DIR) $(B_OBJ_DIR)
					@$(MFC) $(MAKE_FLAGS) $(LFT_DIR)
					@echo "$(YELLOW)Cleaned $(OBJ_DIR)$(DEFAULT)"

fclean:				clean 
					@$(RM) $(NAME)
					@echo "$(RED)Cleaned $(NAME)$(DEFAULT)"

re:					fclean all

.PHONY: 			all clean fclean re