#####   COLORS   #####

END				= \033[0m

GREY			= \033[30m
RED				= \033[31m
GREEN			= \033[32m
YELLOW			= \033[33m
BLUE			= \033[34m
PURPLE			= \033[35m
CYAN			= \033[36m

HIGH_RED		= \033[91m

#####   INFO   #####

NAME			= cub3d

#####   COMMANDS   #####

CC				= gcc
EXTENSION		= c
CFLAGS			= -g #-Wall -Wextra -Werror

#####   MLX   #####
MLX_PATH		= ./mlx/
MLX_LIB			= $(MLX_PATH)libmlx.a
MLX_FLAGS 		= -Lmlx -lmlx -framework OpenGL -framework AppKit

#####   UTILS   #####
EXECUTION		= ./$(NAME)
MD				= mkdir -p
RM				= rm -rf

#####   RESOURCES   #####

INCLUDE			= incl
SRC_DIR			= srcs
OBJ_DIR			= objs

SRC_SUB_DIRS	= $(shell find $(SRC_DIR) -type d)
OBJ_SUB_DIRS	= $(SRC_SUB_DIRS:$(SRC_DIR)%=$(OBJ_DIR)%)

SRCS			= $(foreach DIR, $(SRC_SUB_DIRS), $(wildcard $(DIR)/*.$(EXTENSION)))
OBJS			= $(SRCS:$(SRC_DIR)/%.$(EXTENSION)=$(OBJ_DIR)/%.o)

#####   BASE RULES   #####

all: $(NAME)

$(NAME): minilibx $(OBJ_SUB_DIRS) $(OBJS)
	@ $(CC) $(CFLAGS) $(MLX_FLAGS) $(MLX_LIB) $(OBJS) -o $@
	@ echo "$(GREEN)[+] $(NAME) compiled$(END)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.$(EXTENSION)
	@ $(CC) $(CFLAGS) -I $(INCLUDE) -Imlx -c $< -o $@
	@ echo "$(BLUE)[+] $@ compiled$(END)"

$(OBJ_SUB_DIRS):
	@ $(MD) $(OBJ_SUB_DIRS)
	@ echo "$(PURPLE)[+] $(SRC_DIR) remapped into $(OBJ_DIR) $(END)"

minilibx:
	@make -s -C $(MLX_PATH)

minilibx_clean:
	@make -s clean -C $(MLX_PATH)

clean: minilibx_clean
	@ $(RM) $(OBJ_DIR)
	@ echo "$(YELLOW)[+] $(OBJ_DIR) cleaned$(END)"

fclean: minilibx_clean clean
	@ $(RM) $(NAME)
	@ echo "$(YELLOW)[+] $(NAME) fcleaned$(END)"

re: fclean all

bonus: all

#####   PHONY   #####
.PHONY: all clean fclean re
