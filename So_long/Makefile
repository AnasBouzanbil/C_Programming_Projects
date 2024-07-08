# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 16:54:44 by abouzanb          #+#    #+#              #
#    Updated: 2022/12/12 15:08:38 by abouzanb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BNAME = so_long_bonus

SOURCES = none.c path.c put_img.c check_key.c utils.c main.c
Bsrc = bonus/none_bonus.c bonus/path_bonus.c bonus/put_img_bonus.c bonus/check_key_bonus.c bonus/main_bonus.c bonus/utils_bonus.c
helpsrc  = helpful_functions/ft_strlen.c helpful_functions/ft_itoa.c helpful_functions/ft_split.c\
			helpful_functions/ft_substr.c helpful_functions/ft_strrchr.c helpful_functions/ft_strncmp.c helpful_functions/ft_putnbr_fd.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

CFLAGS = -Wall -Wextra -Werror

LINKS = -l mlx -framework OpenGL -framework Appkit

all : $(NAME)

bonus : $(BNAME)

$(NAME): $(SOURCES) $(helpsrc)
	gcc $(LINKS) $(CFLAGS) $(SOURCES) $(helpsrc) -o $(NAME)
$(BNAME) : $(helpsrc) $(Bsrc)
	gcc $(LINKS) $(CFLAGS) $(helpsrc) $(Bsrc) -o $(BNAME)

clean :
	rm -f $(NAME) $(BNAME)
fclean : clean
	
re : fclean all
