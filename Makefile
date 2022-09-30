NAME = so_long

CC = gcc

OTHERS = ./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c ./ft_printf/ft_printf.c ./ft_printf/ft_printf_utils.c ft_strdup.c window.c window2.c window3.c window4.c window5.c map.c map2.c map3.c map4.c ft_split.c

OBJ = $(OTHERS:.c=.o)

FLAGS = -Wall -Wextra -Werror mlx/libmlx.a -Lmlx  -framework OpenGL -framework AppKit   

RM = rm

all: $(NAME)

$(NAME):$(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	gcc -c -Wall -Wextra -Werror -g $< -o $@

#-fsanitize=address -g

clean: 
		rm  $(OBJ)

fclean: clean
		rm $(NAME)
		make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re