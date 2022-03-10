# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile_Unix.mk                                   :+:    :+:             #
#                                                      +:+                     #
#    By: W2Wizard <w2.wizzard@gmail.com>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/26 21:36:38 by W2Wizard      #+#    #+#                  #
#    Updated: 2022/03/10 16:48:41 by buiterma      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

#//= Files =//#
# /usr/bin/find is explicitly mentioned here for Windows compilation under Cygwin
SHDR	=	src/mlx_vert.c src/mlx_frag.c
SHDRSRC	=	shaders/default.frag shaders/default.vert
LIBS	=	$(shell /usr/bin/find ./lib -iname "*.c")
SRCS	=	$(shell /usr/bin/find ./src -iname "*.c") $(SHDR) $(LIBS)
OBJS	=	${SRCS:.c=.o}

#//= Recipes =//#
all: $(SHDR) $(NAME)

# Convert our shaders to .c files
src/mlx_vert.c: shaders/default.vert
ifeq ($(DB),1)
	@echo "$(GREEN)$(BOLD)Converting shader: $< -> $@ $(RESET)"
endif
	@python3 tools/compile_shader.py $^ > $@

src/mlx_frag.c: shaders/default.frag 
ifeq ($(DB),1)
	@echo "$(GREEN)$(BOLD)Converting shader: $< -> $@ $(RESET)"
endif
	@python3 tools/compile_shader.py $^ > $@

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
	@printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"
endif

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
ifeq ($(DB),1)
	@printf "$(GREEN)$(BOLD)Done\n\n$(RESET)"
endif

clean:
ifeq ($(DB),1)
	@echo "$(RED)Cleaning$(RESET)"
endif
	@rm -f $(OBJS) $(SHDR)

fclean: clean
ifeq ($(DB),1)
	@rm -f $(NAME)
endif

re:	fclean all
