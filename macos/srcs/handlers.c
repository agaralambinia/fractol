#include "../incs/fractol.h"

int key_handle(int keysim, t_fractal *fractal)
{
    if (keysim == XK_Left)
        fractal->shift_x -= 0.5;
    else if (keysim == XK_Right)
        fractal->shift_x += 0.5;
    else if (keysim == XK_Up)
        fractal->shift_y += 0.5;
    else if (keysim == XK_Down)
        fractal->shift_y -= 0.5;
    else if (keysim == XK_minus)
        fractal->iterations -= 10;
    else if (keysim == XK_space) //XK_plus doesn't work
        fractal->iterations += 10;
    else if (keysim == XK_Escape)
        close_handle(fractal);
    fractal_render(fractal);
    return (0);
}

//int mouse_handle(int keysim, t_fractal *fractal)
//{
//    
//}
//
int    close_handle(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection,fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection,fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}