NAME = push_swap
BNAME = checker
srcmain = push_swap.c


SRC = libft/ft_atoi.c libft/ft_isdigit.c libft/ft_split.c libft/ft_strlen.c libft/ft_substr.c libft/ft_lstadd_back_bonus.c \
	libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstlast_bonus.c  \
	complex_sort.c nswap.c is_sorted.c  rotate.c rotate_reverse.c swap_five.c  swap_three.c swap_a_b.c push_b.c store.c



BSRC = libft/ft_atoi.c libft/ft_isdigit.c libft/ft_split.c libft/ft_strlen.c libft/ft_substr.c libft/ft_lstadd_back_bonus.c \
	libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstlast_bonus.c \
	checker_bonus/lpush_b.c checker_bonus/storep.c libft/ft_strncmp.c

CHECK_SRC = checker_bonus/checker_bonus.c checker_bonus/get_input.c checker_bonus/get_next_line/get_next_line.c checker_bonus/get_next_line/get_next_line_utils.c 

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(BNAME)

$(NAME) : $(SRC) $(srcmain)
	cc $(FLAGS) $(SRC) $(srcmain) -o $(NAME)

$(BNAME) : $(BSRC) $(CHECK_SRC)
	cc $(FLAGS) $(BSRC) $(CHECK_SRC) -o $(BNAME) 

clean :
	rm -f $(NAME) $(BNAME)

fclean : clean

re : fclean all
