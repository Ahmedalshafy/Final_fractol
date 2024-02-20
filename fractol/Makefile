# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 07:47:16 by aalshafy          #+#    #+#              #
#    Updated: 2024/02/18 10:45:21 by aalshafy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, main.c hooks.c utils.c render.c coloring.c init.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L minilibx -lmlx -framework OpenGL -framework AppKit
FT_PRINTF = ftprintf
MINILIBX_DIR = minilibx
CC = cc

all: minilibx ft_printf $(NAME) clean
minilibx:
	@echo "Building minilibx..."
	@make -C $(MINILIBX_DIR)
ft_printf:
	@echo "Building ft_printf..."
	@make -C $(FT_PRINTF)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME) -L $(FT_PRINTF) -lftprintf

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)
	make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re minilibx