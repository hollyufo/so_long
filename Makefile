NAME = so_long
SRC = main.c get_next_line.c gnl_utils.c ft_printf.c ft_printf_utils.c parse_map.c map_path.c render_map.c events.c free.c parse_map_utils.c free_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra 
MLX = ./minilibx-linux
LIBS = -L$(MLX) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
