NAME = fractol

SRC = srcs/ft_math.c\
	  srcs/ft_string.c\
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

DEPS = incs/fractol.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

all: ${DEPS} ${NAME}

${NAME}: ${OBJ}
	${CC} -fsanitize=address -I /usr/local/include ${SRC} -o $@ -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
