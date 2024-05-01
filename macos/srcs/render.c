#include "../incs/fractol.h"

void    my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y* img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}

void    handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int i;
    int color;

    i = 0;
    z.x = 0.0;
    z.y = 0.0;

    c.x = scale(x, -2, 2, WIDTH) + fractal->shift_x;
    c.y = scale(y, 2, -2, HEIGHT) + fractal->shift_y;
    while (i < fractal->iterations)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y + z.y) > fractal->hipotenuse)
        {
            color = scale(i, BLACK, WHITE, fractal->iterations);
            my_pixel_put(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->img, LIME_SHOCK);
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixel(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}