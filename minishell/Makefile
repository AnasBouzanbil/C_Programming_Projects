# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 18:51:46 by hel-kadd          #+#    #+#              #
#    Updated: 2023/04/18 01:34:38 by abouzanb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = @cc

CFLAGS = -Wall -Wextra -Werror -I /Users/abouzanb/Desktop/readline-8.2




SRCS =	./parsing/src/parse/lexer/lexer.c \
		./parsing/src/parse/lexer/lexer_utils.c \
		./parsing/src/parse/lexer/lexer_quotes.c \
		./parsing/src/parse/utils/ft_utils.c \
		./parsing/src/parse/utils/ft_utils2.c \
		./parsing/src/parse/utils/ft_str_func.c \
		./parsing/src/parse/utils/ft_str_fun2.c \
		./parsing/src/parse/parsing/parse.c \
		./parsing/src/parse/expand/expand.c \
		./parsing/src/parse/expand/expand_utils.c \
		./parsing/src/parse/expand/expand_test.c \
		./parsing/src/parse/parsing/parse_utils.c \
		./parsing/src/parse/parsing/parse_utils2.c \
		./parsing/src/parse/parsing/file_helping.c \
		./execution/bulit.c ./execution/execution.c \
		./execution/re_libft.c ./execution/small_libft.c \
		./execution/split.c ./execution/split_with_slash.c \
		./execution/utils1.c ./execution/utils2.c  \
		./execution/days/d00.c ./execution/days/d01.c \
		./execution/days/d02.c ./execution/days/d03.c \
		./execution/days/d04.c ./execution/days/export.c \
		./execution/days/d05.c ./execution/days/check_path_and_free_node.c \
		./execution/ft_atoi.c  ./execution/cd_env.c ./execution/days/export_utils.c \
		main.c  ./execution/exit.c ./execution/days/export_utils_two.c ./execution/days/export_utils_3.c


C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

OBJS = $(SRCS:.c=.o)

OBJSBS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)  /Users/abouzanb/Desktop/readline-8.2/libreadline.a -lcurses
		@echo "$(C_GREEN)[parsing CREATED]$(C_RES)"


clean: 
		@rm -f $(OBJS) $(OBJSBS)
		@echo "$(C_RED)[OBJECTS REMOVED]$(C_RES)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(C_RED)[parsing REMOVED]$(C_RES)"

re : fclean all



