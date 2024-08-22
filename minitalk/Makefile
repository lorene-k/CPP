# ------------  COLORS  ----------------------------------------------------- #
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
DEFAULT			=	\033[0m

# ------------  PROJECT  ----------------------------------------------------- #
EXEC_1			=	client
EXEC_2			=	server

# ------------  DIRECTORIES  ------------------------------------------------- #
LFT_DIR			=	libft/

# ------------  SOURCES  ----------------------------------------------------- #
LFT				=	$(LFT_DIR)libft.a

SRC_C			=	client.c
SRC_S			=	server.c

# ------------  FILEPATHS  --------------------------------------------------- #
OBJ_C			=	$(SRC_C:.c=.o)
OBJ_S			=	$(SRC_S:.c=.o)

# ------------  FLAGS  -------------------------------------------------------- #
CFLAGS			=	-Wall -Wextra -Werror -g
LFLAGS			=	-L./$(LFT_DIR) -lft
LIB_FLAGS		=	-lreadline -lncurses

MAKE_FLAGS		=	-s -C
RM_FLAGS		=	-rf

INCLUDES		=	-I/$(LFT_DIR)

# ------------  COMMANDS  ------------------------------------------------------- #
CC				=	cc
MK				=	make all
MFC				=	make fclean
MC				=	make clean
RM				=	rm $(RM_FLAGS)

# ------------  RULES  ------------------------------------------------------- #
all:				${EXEC_1} $(EXEC_2)

$(EXEC_1):			$(OBJ_C) $(LFT)
					@$(CC) $(CFLAGS) -o $(EXEC_1) $(OBJ_C) $(LFLAGS) $(LIB_FLAGS)
					@echo "$(GREEN)Compiled $(EXEC_1)$(DEFAULT)"

$(EXEC_2):			$(OBJ_S) $(LFT)
					@$(CC) $(CFLAGS) -o $(EXEC_2) $(OBJ_S) $(LFLAGS) $(LIB_FLAGS)
					@echo "$(GREEN)Compiled $(EXEC_2)$(DEFAULT)"

%.o:%.c
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LFT):
					@$(MK) $(MAKE_FLAGS) $(LFT_DIR)

clean:	
					@$(MFC) $(MAKE_FLAGS) $(LFT_DIR)
					@$(RM) $(OBJ_C) $(OBJ_S)
					@echo "$(YELLOW)Cleaned object files$(DEFAULT)"

fclean:				clean 
					@$(RM) $(EXEC_1) $(EXEC_2)
					@echo "$(RED)Cleaned $(EXEC_1) and $(EXEC_2) $(DEFAULT)"

re:					fclean all

.PHONY: 			all clean fclean re