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
LEXER_DIR		=	lexer/
PARSER_DIR		=	parser/
UTILS_DIR		=	utils/

# ------------  SOURCES  ----------------------------------------------------- #
LFT				=	libft/libft.a

SRC_FLS			=	main.c \
					loop.c \
					$(UTILS_DIR)clear.c \
					$(UTILS_DIR)error.c \
					$(UTILS_DIR)structs_init.c \
					$(UTILS_DIR)structs_get_prev.c \
					$(LEXER_DIR)lexer_check.c \
					$(LEXER_DIR)lexer_expand.c \
					$(LEXER_DIR)lexer_quotes.c \
					$(LEXER_DIR)lexer_types.c \
					$(LEXER_DIR)lexer_unclosed_quotes.c \
					$(LEXER_DIR)lexer_values.c \
					$(LEXER_DIR)lexer.c \
					$(PARSER_DIR)parse.c \
					$(PARSER_DIR)parser_checker.c \
					$(PARSER_DIR)parser_cmds.c \
					$(PARSER_DIR)parser_files.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FLS))
OBJS			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

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

$(NAME):			$(OBJ_DIR) $(OBJS) $(LFT)
					@$(CC) $(CFLAGS) -o ./$(NAME) $(OBJS) $(LFLAGS) $(LIB_FLAGS)
					@echo "$(GREEN)Compiled $(NAME)$(DEFAULT)"

$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(LEXER_DIR)
					@mkdir -p $(OBJ_DIR)$(PARSER_DIR)
					@mkdir -p $(OBJ_DIR)$(UTILS_DIR)

$(LFT):
					@$(MK) $(MAKE_FLAGS) $(LFT_DIR)

clean:	
					@$(RM) $(OBJ_DIR)
					@$(MFC) $(MAKE_FLAGS) $(LFT_DIR)
					@echo "$(YELLOW)Cleaned $(OBJ_DIR)$(DEFAULT)"

fclean:				clean 
					@$(RM) $(NAME)
					@echo "$(RED)Cleaned $(NAME)$(DEFAULT)"

re:					fclean all

.PHONY: 			all clean fclean re