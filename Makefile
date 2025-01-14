CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = so_long.c data_init.c clean_exit.c clear_win.c \
        draw_player.c movements.c enemy.c event_handlers.c \
        exit.c ft_itoa.c get_next_line.c utils.c utils2.c\
        get_next_line_utils.c imges.c map_check.c player_sprite.c
OBJ = $(SRC:.c=.o)
NAME = so_long
HEADER = so_long.h get_next_line.h mlx.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Llibmlx_Linux.a -lmlx_Linux -L/usr/X11R6/lib -lXext -lX11 -lm -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
.SECONDARY: