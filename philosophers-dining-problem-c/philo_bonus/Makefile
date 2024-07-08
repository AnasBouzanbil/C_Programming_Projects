NAME = philo_bonus

Src = f_atoi.c main_bonus.c src_bonus.c

CFLAGS  = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(Src)
	$(CFLAGS) $(Src) -o $(NAME)

clean : 
	rm -f $(NAME)

fclean :  clean

re : fclean all