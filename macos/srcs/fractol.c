#include "../incs/fractol.h"

int main(int argc, char **argv)
{
    if ((argc == 4) && !(ft_strncmp(ft_tolower_char(argv[1]), "mandelbrot", 11)))
        ft_mandelbrot(argv);
    else if ((argc == 6) && !(ft_strncmp(ft_tolower_char(argv[1]), "julia", 6)))
        ft_julia(argv);
    else if ((argc == 4) && !(ft_strncmp(ft_tolower_char(argv[1]), "burning_ship", 14)))
        ft_burning_ship(argv);
    else
        ft_exit_help();
}