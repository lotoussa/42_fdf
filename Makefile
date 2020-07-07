# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/01 02:57:25 by lotoussa     #+#   ##    ##    #+#        #
#    Updated: 2018/02/12 18:53:40 by lotoussa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re norm

NAME = fdf

SRCS = src/ft_create_sample.c src/ft_different_ligne.c src/ft_init.c src/main.c\
	   src/ft_print_fdf.c src/ft_setpx.c src/ft_key.c src/ft_corner.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

INC = -I minilibx_macos -I libft

HEADERS = fdf.h

LIBS = minilibx_macos/libmlx.a libft/libft.a

EXT_LIBS = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	gcc $(FLAGS) $(LIBS) $(EXT_LIBS) $(OBJS) -o $(NAME)

$(LIBS):
	make -C ./libft
	make -C ./minilibx_macos

./%.o: ./%.c $(HEADERS)
	gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	make -C ./libft re
	make -C ./minilibx_macos re

re2: fclean all

norm:
	norminette $(SRCS) $(HEADERS)
