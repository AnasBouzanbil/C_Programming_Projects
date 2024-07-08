NAME = pipex


SRC = get_comand.c pipex.c ./libft/ft_split_with_slash.c ./libft/ft_substr_withslash.c ./libft/ft_strlen.c ./libft/ft_strnstr.c ./libft/ft_strjoin.c ./libft/ft_split.c ./libft/ft_substr.c

bsrc = ./bonus/get_comand_bonus.c ./bonus/pipex_bonus.c ./libft/ft_split_with_slash.c ./libft/ft_substr_withslash.c ./libft/ft_strlen.c ./libft/ft_strnstr.c ./libft/ft_strjoin.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/ft_strncmp.c ./libft/ft_split.c ./libft/ft_substr.c

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)


$(NAME) : $(SRC)
	cc $(SRC) $(CFLAGS) -o $(NAME)

bonus : $(bsrc)
	cc $(bsrc) $(CFLAGS) -o $(NAME)
clean :
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY : bonus