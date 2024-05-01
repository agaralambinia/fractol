#include "../incs/fractol.h"

void data_init(t_fractal *fractal)
{
    fractal->hipotenuse = 4;
    fractal->iterations = 200;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
}

void events_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handle, fractal);
    mlx_hook(fractal->mlx_window, BottomPress, BottomPressMask, mouse_handle, fractal);
    mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handle, fractal);
}

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        ft_exit_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        ft_exit_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        ft_exit_error();
    }
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    events_init(fractal);
    data_init(fractal);

}