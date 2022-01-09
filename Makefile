# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 17:08:54 by tzeck             #+#    #+#              #
#    Updated: 2022/01/07 20:38:52 by tzeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFILES = main.c

OBJECTS = $(CFILES:.c=.o)

LIBFT_PATH = libft/

CC = gcc

MLX = minilibx_macos/libmlx.a -I minilibx_macos -lmlx -framework OpenGL -framework AppKit -L minilibx_macos

CFLAGS = -Wall -Wextra -Werror

all: pre_makes $(NAME)

pre_makes:
	make -C $(LIBFT_PATH)

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
