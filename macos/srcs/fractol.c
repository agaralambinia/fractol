#include "../incs/fractol.h"

int main(int argc, char **argv)
{
    if ((argc == 2) && !(ft_strncmp(ft_tolower_char(argv[1]), "mandelbrot", 11)))
        ft_mandelbrot();
    else if ((argc == 4) && !(ft_strncmp(ft_tolower_char(argv[1]), "julia", 6)))
        ft_julia(argv[2], argv[3]);
    else if ((argc == 2) && !(ft_strncmp(ft_tolower_char(argv[1]), "burning_ship", 14)))
        ft_burning_ship();
    else
        ft_exit_error();
}