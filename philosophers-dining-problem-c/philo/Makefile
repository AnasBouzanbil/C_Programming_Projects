NAME = philo

Src = F_atoi.c utils.c philo.c src.c

CFLAGS  = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(Src)
	$(CFLAGS) $(Src) -o $(NAME)

clean : 
	rm -f $(NAME)

fclean :  clean

re : fclean all