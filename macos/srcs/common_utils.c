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
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    fractal->zoom = 1.0;
    fractal->min_color = 0;
    fractal->max_color = 16777215;
}

void    fractal_init(t_fractal *f)
{
    f->mlx_connection = mlx_init();
    if (f->mlx_connection == NULL)
        ft_exit_error();
    f->mlx_window = mlx_new_window(f->mlx_connection, f->scale, f->scale, f->name);
    if (f->mlx_window == NULL)
    {
        mlx_destroy_display(f->mlx_connection);
        free(f->mlx_connection);
        ft_exit_error();
    }
    f->img.img_ptr = mlx_new_image(f->mlx_connection, f->scale, f->scale);
    if (f->img.img_ptr == NULL)
    {
        mlx_destroy_window(f->mlx_connection, f->mlx_window);
        mlx_destroy_display(f->mlx_connection);
        free(f->mlx_connection);
        ft_exit_error();
    }
    f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp, &f->img.line_len, &f->img.endian);
}

void    pixel_draw(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}

void    change_color(t_fractal *fractal, int keysim)
{
    if (keysim == XK_a)
    {
        fractal->min_color = 0;
        fractal->max_color = 16777215;
    }
    else if (keysim == XK_z)
    {
        fractal->min_color = 3394764;
        fractal->max_color = 13434624;
    }
    else if ((keysim == XK_s) && (fractal->min_color >= 10000))
    {
        fractal->min_color -= 10000;
        fractal->max_color -= 10000;
    }
    else if ((keysim == XK_d) && (fractal->max_color <= 16767215))
    {
        fractal->min_color += 10000;
        fractal->max_color += 10000;
    }
}
