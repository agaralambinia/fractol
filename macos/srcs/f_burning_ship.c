#include "../incs/fractol.h"

void    ft_burning_ship(char **args)
{
    t_fractal   fractal;
    
    fractal.name = "burning_ship";
    fractal_init(&fractal);
    bs_events_init(&fractal);
    data_init(&fractal);
    bs_render(&fractal);
    mlx_loop(fractal.mlx_connection);
}

void    bs_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 1;
    while (y++ < SCALE)
    {
        x = 1;
        while (x++ < SCALE)
            bs_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

void    bs_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int i;
    int color;

    i = 0;
    z.x = (scale(x, -2, 2, SCALE) * fractal->zoom) + fractal->shift_x;
    z.y = (scale(y, 2, -2, SCALE) * fractal->zoom) + fractal->shift_y;
    c.x = z.x;
    c.y = z.y;
    while (i < fractal->iterations)
    {
        z = sum_complex(abs_square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->hipotenuse)
        {
            color = scale(i, BLACK, WHITE, fractal->iterations);
            pixel_draw(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    pixel_draw(x, y, &fractal->img, NEON_ORANGE);
}