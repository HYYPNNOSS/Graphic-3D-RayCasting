# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btaha <btaha@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 02:34:38 by btaha             #+#    #+#              #
#    Updated: 2023/01/23 02:34:38 by btaha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c initializer.c parsing_filler.c map_utils.c parsing.c check_texture.c mlx_utils.c player_movement.c intersections.c wall_projections.c texture_utils.c for_norminette.c

NAME = cub3D

PATH_OBJ = obj/

CC = cc

FLAGS = -Wall -Wextra -Werror -Imlx

OBJ = $(addprefix $(PATH_OBJ), $(SRC:.c=.o))

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(FLAGS) -o $(NAME) $(SRC) libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

$(OBJ) : $(PATH_OBJ)%.o: %.c  cub3D.h
	@mkdir -p $(dir $@)
	${CC} ${FLAGS} -c $< -o $@

libft/libft.a:
	make -C Libft all

all: $(NAME)

clean:
	make -C libft fclean
	rm -rf $(PATH_OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
