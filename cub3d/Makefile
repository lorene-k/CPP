# ------------  COLORS  ----------------------------------------------------- #
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
DEFAULT			=	\033[0m

# ------------  PROJECT  ----------------------------------------------------- #
NAME			=	cub3d

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR			=	srcs/
INC_DIR			= 	includes/
OBJ_DIR			=	objs/
LFT_DIR			=	libft/
MLX_DIR			=	mlx_linux/
RC_DIR			=	raycaster/
#PARSER_DIR		=	parser/
#UTILS_DIR		=	utils/

# ------------  SOURCES  ----------------------------------------------------- #
LFT				=	libft/libft.a

SRC_FLS			=	main.c \
					$(RC_DIR)raycaster.c \
					$(RC_DIR)utils.c


# ------------  FILEPATHS  --------------------------------------------------- #
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FLS))
OBJS			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# ------------  FLAGS  -------------------------------------------------------- #
CFLAGS			=	-Wall -Wextra -Werror -g
LFLAGS			=	-L./$(LFT_DIR) -lft
LIB_FLAGS		=	-lreadline -lncurses
MLX_FLAGS		=	-L./$(MLX_DIR) -lmlx_Linux -L/usr/lib $(I_MLX) -lXext -lX11 -lm -lz

MAKE_FLAGS		=	-s -C
RM_FLAGS		=	-rf

I_SRC			= 	-I/$(INC_DIR)
I_MLX			=	-I/$(MLX_DIR)
INCLUDES		=	$(I_SRC) -I/usr/include $(I_MLX)

# ------------  COMMANDS  ------------------------------------------------------- #
CC				=	cc
MK				=	make all
MFC				=	make fclean
MC				=	make clean
RM				=	rm $(RM_FLAGS)

# ------------  RULES  ------------------------------------------------------- #
all:				${NAME}

$(NAME):			$(OBJ_DIR) $(OBJS) $(LFT) $(MLX)
					@$(CC) $(CFLAGS) -o ./$(NAME) $(OBJS) $(LFLAGS) $(LIB_FLAGS)
					@echo "$(GREEN)Compiled $(NAME)$(DEFAULT)"

-include $(DEPS)
$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(PARSER_DIR)
					@mkdir -p $(OBJ_DIR)$(UTILS_DIR)

$(LFT):
					@$(MK) $(MAKE_FLAGS) $(LFT_DIR)

$(MLX):
					@$(MK) $(MAKE_FLAGS) $(MLX_DIR)
					@echo "$(GREEN)Compiled $(MLX)"

clean:	
					@$(RM) $(OBJ_DIR)
					@$(MFC) $(MAKE_FLAGS) $(LFT_DIR)
					@$(MC) $(MAKE_FLAGS) $(MLX_DIR)
					@echo "$(YELLOW)Cleaned $(OBJ_DIR)$(DEFAULT)"

fclean:				clean 
					@$(RM) $(NAME)
					@echo "$(RED)Cleaned $(NAME)$(DEFAULT)"

re:					fclean all

.PHONY: 			all clean fclean re