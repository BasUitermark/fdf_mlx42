#===============================================================================: Filename
NAME		= fdf

#===============================================================================: Directory paths
SRCS_DIRS	= $(addprefix src/, $(dir))
OBJS_DIRS	= $(addprefix objs/, $(dir))

#===============================================================================: Source to object conversion location
OBJS		= $(subst src, objs, $(SRCS:.c=.o))

#===============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#===============================================================================: Compile variables
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf
MKDIR		= mkdir -p objs
HEADERS		= -I $(MLX42) -I $(LIBFT) -I $(FDF)
OS			= $(shell uname)

#===============================================================================: Include files
FDF			= include
MLX42		= include/MLX42
LIBFT		= include/libft

#===============================================================================: OS checker
ifeq ($(OS),Linux)
			GLFW = include/MLX42/libmlx42.a -ldl -lglfw -I MLX42/include -g
else
			GLFW = -lglfw -L "/Users/buiterma/.brew/opt/glfw/lib/"
endif

#===============================================================================: Sourcefiles
SRCS		= $(addprefix src/, $(addsuffix .c, \
			draw_line \
			parse_map \
			initialize \
			key_hooks \
			error \
			project_map \
			main))

#===============================================================================: Make commands
all: message mlx libft $(NAME)

#===============================================================================: Main compile
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(GLFW) $(HEADERS) $(LIBFT)/libft.a $(MLX42)/libmlx42.a -o $(NAME)
	@printf "$(GREEN)✅Executable \"$(NAME)\" created!$(RESET)\n\n"

#===============================================================================: C file compile
objs/%.o: src/%.c
	@$(MKDIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
		@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#===============================================================================: Executable run command
run: cleanfdf all
	@./$(NAME) maps/$(MAP)

#===============================================================================: Build messages
message:
	@printf "$(GREEN)You are using $(OS)$(RESET)\n"
	@printf "$(MAGENTA)🔨Building \"$(NAME)\"\n$(RESET)\n"

#===============================================================================: MLX42 Compile
mlx:
	@$(MAKE) -C $(MLX42)

#===============================================================================: Libft Compile
libft:
	@$(MAKE) -C $(LIBFT)

#===============================================================================: Remove all object files
clean:
	@$(RM) objs/
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(MLX42) clean
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove project object files & executable
cleanfdf:
	@$(RM) objs/
	@$(RM) $(NAME)
	@printf "$(RED)🧹Removed current objects & current executable for \"$(NAME)\"$(RESET)\n"

#===============================================================================: Remove all object files and executable
fclean:
	@$(RM) objs/
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(MLX42) fclean
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"
	@printf "$(RED)🧹Removed \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files, executable and remake executable
re: fclean all

#===============================================================================: To not confuse make
.PHONY: all, clean, fclean, re, message, run