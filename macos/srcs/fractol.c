#include "../incs/fractol.h"

int main(int argc, char **argv)
{
    t_fractal   fractal;

    if ((argc == 2 && !(ft_strncmp(argv[1], "mandelbrot", 11)))
        || (argc == 4 && !(ft_strncmp(argv[1], "julia", 6))))
    {
        fractal.name = argv[1]; //TODO WHY POINT
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        ft_exit_error();
    }
}