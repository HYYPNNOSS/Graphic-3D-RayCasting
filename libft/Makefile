# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btaha <btaha@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 03:07:22 by btaha             #+#    #+#              #
#    Updated: 2023/01/23 03:08:25 by btaha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Src = ft_strlen.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c\
 	ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_toupper.c ft_tolower.c ft_atoi.c ft_memcmp.c ft_memset.c ft_memcpy.c\
	ft_memmove.c ft_memchr.c ft_bzero.c ft_calloc.c ft_strdup.c ft_substr.c\
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strcmp.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_strnlen.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstremove.c ft_search.c get_len_row.c ft_free.c\
 	gnl/get_next_line.c gnl/get_next_line_utils.c

Cc = gcc
Flags = -Wall -Wextra -Werror -g
Name = libft.a

Obj = $(Src:.c=.o)

$(Name): $(Obj)
	ar cr $(Name) $(Obj)

all: $(Name)

gnl/%.o: gnl/%.c 
	$(Cc) $(Flags) -c -o $@ $< 

%.o: %.c libft.h
	$(Cc) $(Flags) -c -o $@ $<

bonus: $(Obj)
	ar cr $(Name) $(Obj)

clean:
	rm -rf $(Obj)

fclean: clean
	rm -rf $(Name) get_next_line_utils.o get_next_line.o

re: fclean all

.PHONY: all bonus clean fclean re
