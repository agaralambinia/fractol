NAME = fractol

SRC = srcs/f_common.c\
	  srcs/fractol.c\
	  srcs/init.c\
	  srcs/math_utils.c\
	  srcs/render.c\
	  srcs/handlers.c\

OBJ = ${SRC:.c=.o}

LIBFT_PATH	= ./incs/libft
LIBFT_NAME	= libft.a

MINILIBX_PATH	= ./incs/minilbx
MINILIBX_NAME	= libmlx.a
#MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
X11_FLAGS = -L/usr/X11/include/../lib -lXext -lX11

DEPS = incs/fractol.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

all: ${LIBFT_PATH}/${LIBFT_NAME} ${MINILIBX_PATH}/${MINILIBX_NAME} ${DEPS} ${NAME}

${NAME}: ${OBJ}
	${CC} ${SRC} $(X11_FLAGS) -o $@ ${LIBFT_PATH}/${LIBFT_NAME} ${MINILIBX_PATH}/${MINILIBX_NAME}

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

${MINILIBX_PATH}/${MINILIBX_NAME}:
	make -C ${MINILIBX_PATH}

clean:
	rm -f ${OBJ}
	cd $(LIBFT_PATH) && make clean
	cd $(MINILIBX_PATH) && make clean

fclean: clean
	rm -f ${NAME}
	cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re
