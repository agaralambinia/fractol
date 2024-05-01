#include "../incs/fractol.h"

int    close_handle(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection,fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection,fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

void data_init(t_fractal *fractal)
{
    fractal->hipotenuse = 4;
    fractal->iterations = 200;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    fractal->zoom = 1.0;
}

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        ft_exit_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, SCALE, SCALE, fractal->name);
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        ft_exit_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, SCALE, SCALE);
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        ft_exit_error();
    }
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}

void    pixel_draw(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}
