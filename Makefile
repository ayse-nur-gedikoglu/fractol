#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 21:28:23 by agedikog          #+#    #+#              #
#    Updated: 2025/04/02 13:09:55 by agedikog         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME        = fractol
MAKEFLAGS  += --no-print-directory

OS          = $(shell uname)
SRCDIR      = .
INCDIR      = .
OBJDIR      = ./obj
MLXDIR      = ./minilibx-linux
MLX_REPO    = https://github.com/42paris/minilibx-linux.git

SRC         = main.c fractals.c \
				core.c utils.c events.c color.c events_hook.c

OBJ         = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

ifeq ($(OS), Linux)
    MLX_LNK = -L$(MLXDIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
else
    MLXDIR  = ./miniLibX
    MLX_LNK = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
endif

MLX_INC     = -I$(MLXDIR)

all: obj $(MLXDIR) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(MLXDIR):
	@if [ ! -d "$(MLXDIR)" ]; then \
		echo "Cloning Minilibx Repository"; \
		git clone $(MLX_REPO) $(MLXDIR); \
	fi
	@echo "Building Minilibx Library"
	@make -C $(MLXDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $< into object file"
	@$(CC) $(CFLAGS) $(MLX_INC) -I$(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	@echo "Linking object files to create the final executable"
	@$(CC) $(OBJ) $(MLX_LNK) -o $(NAME)

bonus: obj $(MLXDIR) $(BONUS_OBJ)
	@echo "Compiling bonus files"
	@$(CC) $(BONUS_OBJ) $(MLX_LNK) -o $(NAME)_bonus

clean:
	@echo "Cleaning object files"
	@rm -rf $(OBJDIR)/*.o

fclean: clean
	@echo "Cleaning all built files"
	@rm -f $(NAME) $(NAME)_bonus
	@rm -rf $(MLXDIR)
	@rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re bonus