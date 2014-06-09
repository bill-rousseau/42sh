# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shedelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/08 18:27:17 by shedelin          #+#    #+#              #
#    Updated: 2014/06/04 18:04:15 by shedelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DIRLIB = libft/

DIRSRC = srcs/

DIRH = includes/

SRC = sh_main.c \
      sh_analyze.c \
      sh_automaton.c \
      sh_cd.c \
      sh_cursor.c \
      sh_echo.c \
      sh_env.c \
      sh_env_tools.c \
      sh_error.c \
      sh_exec_and.c \
      sh_exec_cmd.c \
      sh_exec_left.c \
      sh_exec_pipe.c \
      sh_exec_right.c \
      sh_exec_tree.c \
      sh_exec_word.c \
      sh_execkey.c \
      sh_exit.c \
      sh_fork.c \
      sh_get_line.c \
      sh_jobs.c \
      sh_lex_and.c \
      sh_lex_left.c \
      sh_lst_lex.c \
      sh_movecursor.c \
      sh_pars_and.c \
      sh_pars_left.c \
      sh_prompt.c \
      sh_setenv.c \
      sh_signal.c \
      sh_term.c \
      sh_term_tools.c \
      sh_tools.c \
      sh_tree.c \
      sh_unsetenv.c \
      sh_wait.c \
      sh_winsize.c
OBJ = $(SRC:.c=.o)

all: init $(NAME)

init:
	@echo "\033[0;32m 					$(NAME) PROJECT\033[0m"

$(NAME): $(OBJ)
	@make -s -C $(DIRLIB)
	@$(CC) $(FLAGS) -o $(NAME) $^ -I$(DIRLIB) -I$(DIRH) -L$(DIRLIB) -lft -ltermcap
	@echo "\033[1;32m 42sh: OK\033[0m"

%.o: $(DIRSRC)%.c
	@echo -n .
	@$(CC) $(FLAGS) -o $@ -c $< -I$(DIRLIB)$(DIRH) -I$(DIRH)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(DIRLIB)
	@echo "\033[4;32mDeleted:\033[0;33m $(OBJ)\033[0m"

fclean: clean
	@make -C $(DIRLIB) $@
	@rm -f $(NAME)
	@echo "\033[4;32mDeleted:\033[0;33m $(NAME)\033[0m"

re: fclean all

.PHONY: all clean fclean re
