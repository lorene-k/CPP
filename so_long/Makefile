# ------------  COLORS  ----------------------------------------------------- #
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
DEFAULT			=	\033[0m

# ------------  PROJECT  ----------------------------------------------------- #
NAME			=	so_long

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR			=	src/
OBJ_DIR			=	objs/
LFT_DIR			=	src/libft/
MLX_DIR			=	minilibx_linux/

# ------------  SOURCES  ----------------------------------------------------- #
LFT				=	libft.a

HEADER			=	$(SRC_DIR)so_long.h

SRC_FLS			=	main.c \
					check_map.c \
					check_path.c \
					init_structs.c \
					utils_check.c \

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FLS))
OBJS			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SRCS))

# ------------  FLAGS  -------------------------------------------------------- #
LFLAGS			=	-L./$(LFT_DIR)
CFLAGS			=	-Wall -Wextra -Werror -g
MAKE_FLAGS		=	-s -C
MLX_FLAGS		=	-ldl -Imlx -Lminilibx_linux/ -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/
RM_FLAGS		=	-rf

# ------------  COMMANDS  ------------------------------------------------------- #
CC				=	cc
MK				=	make all
MC				=	make fclean
RM				=	rm $(RM_FLAGS)

# ------------  RULES  ------------------------------------------------------- #
all:				${NAME}

$(NAME):			$(OBJS) $(LFT)
					@$(CC) $(CFLAGS) -o ./$(NAME) $(OBJS) $(LFLAGS) -lft
					@echo "$(GREEN)Compiled $(NAME)"

$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) -c $< -o $@
					@if [ "$(PRINTED_MSG)" = "false" ]; then \
					echo "$(DEFAULT)Object files created"; \
					PRINTED_MSG := true; \
					fi

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@echo "$(DEFAULT)Created $(OBJ_DIR)"

$(LFT):
					@$(MK) $(MAKE_FLAGS) $(LFT_DIR)

clean:	
					@$(RM) $(OBJ_DIR)
					@$(MC) $(MAKE_FLAGS) $(LFT_DIR)
					@echo "$(YELLOW)Cleaned objects & libft"

fclean:				clean 
					@$(RM) $(NAME)
					@echo "$(YELLOW)Cleaned executable"

re:				fclean all

.PHONY: 		all clean fclean re
