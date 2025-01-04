CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = solong
SRCS = main.c 
MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
    $(CC) $(CFLAGS) $(SRCS) $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
    rm -f $(NAME) $(NAME)_bonus
    clean -C $(MLX_DIR)

re: fclean all