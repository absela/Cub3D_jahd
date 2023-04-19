NAME = cub3d

SRCS = mandatory/cub3d.c mandatory/parsing1.c mandatory/parsing2.c mandatory/parsing3.c mandatory/parsing4.c mandatory/utils.c mandatory/graphic.c mandatory/init_all.c mandatory/raycasting.c mandatory/raycasting1.c mandatory/utils_color.c mandatory/render3d.c mandatory/moves.c mandatory/moves_sec.c mandatory/textures.c

BSRCS = bonus/cub3d.c bonus/parsing1.c bonus/parsing2.c bonus/parsing3.c bonus/parsing4.c bonus/utils.c bonus/graphic.c bonus/init_all.c bonus/raycasting.c bonus/raycasting1.c bonus/utils_color.c bonus/render3d.c bonus/moves.c bonus/moves_sec.c bonus/textures.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CC = cc

HDR = include/cub3d.h

HDRS = include/cub3d_bonus.h

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o : %.c  ${HDR} ${HDRS}
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	cd libft && make
	cd ..
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit

bonus: $(BOBJS)
	cd libft && make
	cd ..
	$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	cd libft && make fclean
	$(RM) $(NAME)

re: fclean all

