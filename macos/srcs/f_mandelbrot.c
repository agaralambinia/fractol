#include "../incs/fractol.h"
#include <stdio.h>

void    ft_mandelbrot(char **args)
{
    t_fractal   fractal;
    
    fractal.name = "mandelbrot";
    fractal.scale = ft_atoui(args[2]);
    fractal.iterations = ft_atoi(args[3]);
    fractal_init(&fractal);
    m_events_init(&fractal);
    data_init(&fractal);
    m_render(&fractal);
    mlx_loop(fractal.mlx_connection);
}

void    m_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 1;
    while (y++ < fractal->scale)
    {
        x = 1;
        while (x++ < fractal->scale)
            m_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

void    m_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int i;
    int color;

    i = 0;
    z.x = (scale(x, -2, 2, fractal->scale) * fractal->zoom) + fractal->shift_x;
    z.y = (scale(y, 2, -2, fractal->scale) * fractal->zoom) + fractal->shift_y;
    c.x = z.x;
    c.y = z.y;
    while (i < fractal->iterations)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->hipotenuse)
        {
            color = scale(i, fractal->min_color, fractal->max_color, fractal->iterations);
            pixel_draw(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    pixel_draw(x, y, &fractal->img, fractal->max_color);
}