NAME = so_long

FILENAMES = error_map.c\
exit_game.c\
flood_fill.c\
map_validation.c\
main.c\
movements.c\
render_graphic.c\
get_next_line.c\
get_next_line_utils.c\


LIBNAMES = ./libft/libft.a\
./minilibx-linux/libmlx.a

LIBFT = ./libft/
MINILIBX =./minilibx-linux/

CFLAGS = -Wall -Werror -Wextra
CC = clang
MLXFLAGS = -lX11 -lXext
OBJS    := ${FILENAMES:.c=.o}

all: libmlx $(NAME)

libmlx:
		make -C libft
		make -C $(MINILIBX)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(FILENAMES) $(LIBNAMES) $(MLXFLAGS) -o $(NAME) 
	

clean:
		make fclean -C $(LIBFT)
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBMLX)/libmlx42.a

re: fclean all

.PHONY: all clean fclean re