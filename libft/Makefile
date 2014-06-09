# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/08 20:05:50 by shedelin          #+#    #+#              #
#    Updated: 2014/03/14 15:59:30 by tmerlier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
FLAGS=-Wall -Werror -Wextra -g
DIRSRC=srcs/
HEADER=includes/
SRC=ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strndup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strcdup.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_open.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_istab.c \
	ft_iswhite.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putendl.c \
	ft_putchar_fd.c \
	ft_putchar_col.c \
	ft_putstr_fd.c \
	ft_putstr_col.c \
	ft_putendl_fd.c \
	ft_putendl_col.c \
	ft_putnbr_fd.c \
	ft_itoa.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strcequ.c \
	ft_strnew.c \
	ft_strsub.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_memalloc.c \
	ft_strjoin.c \
	ft_strcjoin.c \
	ft_memdel.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_lstcount.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstaddend.c \
	ft_lstiter.c \
	ft_lstswap.c \
	ft_tabdel.c \
	ft_printtab.c \
	ft_put_log.c \
	get_next_line.c 
OBJO=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJO)
		@ranlib $(NAME)
		@echo "\n\033[1;32mlibft: OK\033[0m"

clean:
		@rm -f $(OBJO)

fclean: clean
		@rm -f $(NAME)

re: fclean all

%.o: $(DIRSRC)%.c
	@echo -n .
	@gcc -o $@ -c $< $(FLAGS) -I $(HEADER)
	@ar -qc $(NAME) $@

.PHONY: all clean fclean re
