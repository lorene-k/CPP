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
MLX_DIR			=	mlx_linux/

# ------------  SOURCES  ----------------------------------------------------- #
LFT				=	libft.a
MLX				=	libmlx_Linux.a

I_SRC			= 	-I/$(SRC_DIR)
I_MLX			=	-I/$(MLX_DIR)
INCLUDES		=	$(I_SRC) -I/usr/include $(I_MLX) 

SRC_FLS			=	main.c \
					check_map.c \
					check_path.c \
					init_structs.c \
					utils_check.c \
					init_game.c \

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FLS))
OBJS			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SRCS))

# ------------  FLAGS  -------------------------------------------------------- #
LFLAGS			=	-L./$(LFT_DIR) -lft
CFLAGS			=	-Wall -Wextra -Werror -g
MAKE_FLAGS		=	-s -C
MLX_FLAGS		=	-L./$(MLX_DIR) -lmlx_Linux -L/usr/lib $(I_MLX) -lXext -lX11 -lm -lz
RM_FLAGS		=	-rf

# ------------  COMMANDS  ------------------------------------------------------- #
CC				=	cc
MK				=	make all
MFC				=	make fclean
MC				=	make clean
RM				=	rm $(RM_FLAGS)

# ------------  RULES  ------------------------------------------------------- #
all:				${NAME}

$(NAME):			$(OBJS) $(LFT) $(MLX)
					@$(CC) $(CFLAGS) -o ./$(NAME) $(OBJS) $(LFLAGS) $(MLX_FLAGS)
					@echo "$(GREEN)Compiled $(NAME)"

$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
					@if [ "$(PRINTED_MSG)" = "false" ]; then \
					echo "$(DEFAULT)Object files created"; \
					PRINTED_MSG := true; \
					fi

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@echo "$(DEFAULT)Created $(OBJ_DIR)"

$(LFT):
					@$(MK) $(MAKE_FLAGS) $(LFT_DIR)
					@echo "$(GREEN)Compiled $(LFT)"

$(MLX):
					@$(MK) $(MAKE_FLAGS) $(MLX_DIR)
					@echo "$(GREEN)Compiled $(MLX)"

clean:	
					@$(RM) $(OBJ_DIR)
					@$(MFC) $(MAKE_FLAGS) $(LFT_DIR)
					@$(MC) $(MAKE_FLAGS) $(MLX_DIR)
					@echo "$(YELLOW)Cleaned objects & libft"

fclean:				clean 
					@$(RM) $(NAME)
					@echo "$(YELLOW)Cleaned executable"

re:					fclean all

.PHONY: 			all clean fclean re