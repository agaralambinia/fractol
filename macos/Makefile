NAME = fractol

SRC = srcs/ft_common.c\
	  srcs/fractol.c\
	  srcs/common_utils.c\
	  srcs/ft_atod.c\
	  srcs/f_julia.c\
	  srcs/f_mandelbrot.c\
	  srcs/f_burning_ship.c\
	  srcs/f_j_handlers.c\
	  srcs/f_m_handlers.c\
	  srcs/f_bs_handlers.c\
	  srcs/output.c

OBJ = ${SRC:.c=.o}

LIBFT_PATH	= ./incs/libft
LIBFT_NAME	= libft.a

MINILIBX_PATH	= ../../minilbx
MINILIBX_NAME	= libmlx.a
#MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
X11_FLAGS = -L/usr/X11/include/../lib -lXext -lX11

DEPS = incs/fractol.h

CC = cc
#CFLAGS = -Werror

#${CFLAGS}
.c.o:
	${CC} -Imlx -c $< -o ${<:.c=.o}

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
