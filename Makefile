#==Filename==#
NAME = fdf

#==Directory paths==#
SRCS_DIRS	= $(addprefix src/, $(dir))
OBJS_DIRS	= $(addprefix objs/, $(dir))

#==Source to object convertion location==#
OBJS		= $(subst src, objs, $(SRCS:.c=.o))

#==Compile variables==#
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

#==Include files==#
FDF			= include/
MLX42		= include/MLX42
LIBFT		= include/libft
GLFW		= -lglfw -L "/Users/buiterma/.brew/opt/glfw/lib/"

#==Headers==#
HEADERS		= -I $(MLX42) -I $(LIBFT) -I $(FDF)

#==Color codes==#
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#==Sourcefiles==#
#Note: Only filename needed. "addprefix" and "addsuffix" add filepath and filetype.
SRCS		= $(addprefix src/, $(addsuffix .c, \
			draw_line \
			parse_map \
			initialize \
			key_hooks \
			error \
			project_map \
			main))

all: message mlx libft $(NAME)

message:
	@printf "$(MAGENTA)Compiling FdF...\n$(RESET)"

objs/%.o: src/%.c
	@mkdir -p objs
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(GLFW) $(HEADERS) $(LIBFT)/libft.a $(MLX42)/libmlx42.a -o $(NAME)
	@printf "$(GREEN)Program FdF created!$(RESET)\n"

#==MLX42 Compile==#
mlx:
	@$(MAKE) -C $(MLX42)

#Libft Compile==#
libft: 
	@$(MAKE) -C $(LIBFT)

#==Remove object files==#
clean:
		@$(RM) $(OBJS)
		@$(RM) -r $(DIR_OBJS)
		@$(MAKE) -C $(LIBFT) clean
		@$(MAKE) -C $(MLX42) clean
		@printf "$(RED)Removed objects!$(RESET)\n"

#==Remove object files and library file==#
fclean: clean
		@$(RM) $(NAME)
		@$(MAKE) -C $(LIBFT) fclean
		@$(MAKE) -C $(MLX42) fclean
		@printf "$(RED)Removed FdF!$(RESET)\n"

#==Remove object files, library file and remake library==#
re:		fclean all

#==To not confuse make==#
.PHONY: all, clean, fclean, re, message