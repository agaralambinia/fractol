#include "../incs/fractol.h"

void    ft_julia(char **args)
{
    t_fractal   fractal;
    
    fractal.name = "julia";
    fractal.julia_x = ft_atod(args[2]);
	fractal.julia_y = ft_atod(args[3]);
    fractal_init(&fractal);
    j_events_init(&fractal);
    data_init(&fractal);
    j_render(&fractal);
    mlx_loop(fractal.mlx_connection);
}

void    j_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 1;
    while (y++ < SCALE)
    {
        x = 1;
        while (x++ < SCALE)
            j_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

void    j_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int i;
    int color;

    i = 0;
    z.x = (scale(x, -2, 2, SCALE) * fractal->zoom) + fractal->shift_x;
    z.y = (scale(y, 2, -2, SCALE) * fractal->zoom) + fractal->shift_y;
    c.x = (fractal->julia_x);
    c.y = (fractal->julia_y);
    while (i < fractal->iterations)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fractal->hipotenuse)
        {
            color = scale(i, BLACK, WHITE, fractal->iterations);
            pixel_draw(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    pixel_draw(x, y, &fractal->img, WHITE);
}