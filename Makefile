# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sramos <sramos@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2024/06/03 11:51:17 by sramos        #+#    #+#                  #
#    Updated: 2024/07/30 13:45:22 by sramos        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c\
map_checker.c\
map_checker_utils.c\
map_checker_path.c\
map_checker_path_utils.c\
parser.c\
gnl/get_next_line.c\
gnl/get_next_line_utils.c\
init_textures.c\
init_game.c\
key_actions.c\
c_cleaner.c\
end_game.c

OBJ = $(SRC:%.c=%.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -Ilibft -IMLX42 #-g #-fsanitize=address
MLXFLAGS = -ldl -lglfw -lm -lpthread
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX42_PATH = ./MLX42/build
MLX42 = $(MLX42_PATH)/libmlx42.a


all : $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRC) -L$(LIBFT_PATH) -lft -L$(MLX42_PATH) -lmlx42 -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MLX42):
	make -C $(MLX42_PATH) all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all, clean, fclean, re