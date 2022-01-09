# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tom <tom@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 17:08:54 by tzeck             #+#    #+#              #
#    Updated: 2022/01/09 16:50:53 by tom              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFILES = src/main.c src/utils.c src/draw.c src/formulars.c

OBJECTS = $(CFILES:.c=.o)

LIBFT_PATH = libft/

MLX_PATH = minilibx_macos/

CC = gcc

MLX = minilibx_macos/libmlx.a -I minilibx_macos -lmlx -framework OpenGL -framework AppKit -L minilibx_macos

CFLAGS = -Wall -Wextra -Werror

all: pre_makes $(NAME) clean

pre_makes:
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX) $(LIBFT_PATH)libft.a -o $(NAME)

bonus: all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
