NAME = philo

Src = f_atoi.c main.c src.c

CFLAGS  = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(Src)
	$(CFLAGS) $(Src) -o $(NAME)

clean : 
	rm -f $(NAME)

fclean :  clean

re : fclean all