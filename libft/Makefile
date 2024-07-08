SRC = ft_isascii.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c ft_isdigit.c ft_memcpy.c ft_split.c ft_strlen.c \
		ft_tolower.c ft_atoi.c ft_isprint.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c ft_bzero.c ft_isupper.c ft_memset.c ft_strdup.c \
		ft_strncmp.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_isalnum.c ft_putendl_fd.c \
		ft_strjoin.c ft_strrchr.c ft_isalpha.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c
bons = ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstnew_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_front_bonus.c ft_lstdelone_bonus.c

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a # this is the name of the library that will be created

O_SRC = $(SRC:.c=.o) # this is the object files that will be created 
O_BONS = $(bons:.c=.o) # this is the object files that will be created

all : $(NAME) # this is the rule that will be executed when you type "make"

$(NAME) : $(O_SRC) # this is the rule that will be executed when you type "make" and that will create the library also it will create the object files that are needed byb calling the implicit rule 
	ar -rc $(NAME) $(O_SRC)  # this is the command that will create the library

clean : # this is the rule that will be executed when you type "make clean"
	rm -f $(O_SRC) # this is the command that will delete the object files
	rm -f $(O_BONS) # this is the command that will delete the object files

fclean : clean # this is the rule that will be executed when you type "make fclean" and that will delete the library also it will call the clean rule
	rm  -f $(NAME) # this is the command that will delete the library

bonus : $(O_BONS) $(O_SRC)
	ar -rc $(NAME) $(O_BONS) $(O_SRC)

re : fclean all # this is the rule that will be executed when you type "make re" and that will call the fclean rule and the all rule
