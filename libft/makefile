# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:10:59 by lotoussa          #+#    #+#              #
#    Updated: 2018/01/11 11:23:17 by lotoussa    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c get_next_line.c ft_strrev.c \
	  ft_sqrt.c \
	  ft_printf.c pf_c.c pf_d.c pf_i.c pf_o.c pf_p.c pf_s.c pf_u.c \
	  pf_x.c pf_upper_c.c pf_upper_d.c pf_upper_o.c pf_upper_s.c \
	  pf_upper_u.c pf_upper_x.c pf_special.c pf_flags.c pf_modif.c \
	  pf_multi.c pf_type.c pf_litoa_base.c pf_luitoa_base.c pf_number.c \
	  pf_string_prec.c pf_string_width.c pf_unicode.c pf_percent.c \
	  pf_hashtag.c pf_invalid_type.c pf_strsub.c

OBJ = $(SRC:.c=.o)

HEADER = libft.h

CC = gcc

CFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)

./%.o: ./%.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
