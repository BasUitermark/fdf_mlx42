NAME = fdf

#Directory names
DIR_SRCS	= src
DIR_OBJS	= objs

SRCS_DIRS	= $(addprefix $(DIR_SRCS)/, $(dir))
OBJS_DIRS	= $(addprefix $(DIR_OBJS)/, $(dir))

SRCS = $(addprefix src/, $(addsuffix .c, \
		draw_line \
		parse_map \
		intialize \
		key_hooks \
		error \
		main))

#Object destination for .c files
OBJS	= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

#Color codes
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
BOLD = \033[1m
RESET = \033[0m

#Include files
FDF = src/
MLX = include/mlx
LIBFT = include/libft

all: $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@printf "$(MAGENTA)Compiling: $(BLUE)$<\n$(RESET)"
	@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@

mlx:
	@printf "$(MAGENTA)Compiling MLX\n$(RESET)"
	@$(MAKE) -C $(MLX)

libft: 
	@printf "$(MAGENTA)Compiling LIBFT\n$(RESET)"
	@$(MAKE) -C $(LIBFT)

#Remove object files
clean:
		@$(RM) $(OBJS)
		@$(RM) -r $(DIR_OBJS)
		@printf "\n$(RED)All objects removed!$(RESET)\n"

#Remove object files and library file
fclean: clean
		@$(RM) $(NAME)
		@printf "\n$(RED)Library $(NAME) removed!$(RESET)\n"

#Remove object files, library file and remake library
re:		fclean all

#
.PHONY: all, clean, fclean, re