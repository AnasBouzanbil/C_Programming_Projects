NAME = cub3d
SRCS = main.c cub3d_utils1.c cub3d_utils2.c get_next_line.c ft_atoi.c get_next_line_utils.c cub3d_utils3.c ft_split.c cub3d_utils4.c cub3d_utils5.c cub3d_utils6.c cub3d_utils7.c cub3d_utils8.c cub3d_utils9.c cub3d_utils10.c 
OBJS = $(SRCS:%.c=%.o)



all : $(NAME)

$(NAME) : $(SRCS)
	cc -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

	
clean :
	rm -rf $(NAME)
fclean : clean
	

re: fclean all

