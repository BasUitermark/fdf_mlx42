#==Filename==#
NAME		= libft.a

SRCS_DIRS	= $(addprefix src/, $(dir))
OBJS_DIRS	= $(addprefix objs/, $(dir))

#==Source to object convertion location==#
OBJS		= $(subst src, objs, $(SRCS:.c=.o))

#==Compile variables==#
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

#==Color codes==#
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#==Sourcefiles==#
#Note: Only filename needed. "addprefix" and "addsuffix" add filepath and filetype.
SRCS		= $(addprefix src/, $(addsuffix .c, \
			ft_abs \
			ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_dlstadd_back \
			ft_dlstadd_front \
			ft_dlstdel_node \
			ft_dlstfirst \
			ft_dlstinsert_after \
			ft_dlstlast \
			ft_dlstnew \
			ft_dlstsize \
			ft_fprintf \
			ft_get_next_line \
			ft_intlen \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_islower \
			ft_isspace \
			ft_isupper \
			ft_isprint \
			ft_itoa \
			ft_itoa_u \
			ft_itoa_base \
			ft_lstnew \
			ft_lstadd_front \
			ft_lstsize \
			ft_lstlast \
			ft_lstadd_back \
			ft_lstdelone \
			ft_lstclear \
			ft_lstiter \
			ft_lstmap \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_neg \
			ft_pos \
			ft_printcarray \
			ft_printiarray \
			ft_printlist \
			ft_printdlist \
			ft_printf \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putnbr_base_fd \
			ft_putstr_fd \
			ft_split \
			ft_strappend \
			ft_strchr \
			ft_strclen \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncat \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtolower \
			ft_strtoupper \
			ft_strtrim \
			ft_substr \
			ft_tolower \
			ft_toupper))

#==Compile==#
all: message $(NAME)

message: 
	@printf "$(MAGENTA)Compiling libft...\n$(RESET)"

objs/%.o: src/%.c
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)\rCompiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"

#==File Compile==#
$(NAME): $(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@printf "$(GREEN)Library $(NAME) created!$(RESET)\n\n"

#==Remove object files==#
clean:
		@$(RM) -r objs
		@printf "$(RED)Removed all libft objects!$(RESET)\n\n"

#==Remove object files and library file==#
fclean: clean
		@$(RM) $(NAME)
		@printf "$(RED)$(RESET)\n"

#==Remove object files, library file and remake library==#
re:		fclean all

.PHONY: all, clean, fclean, re, message
