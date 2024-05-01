#include "../incs/fractol.h"

void j_events_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, j_key_handle, fractal);
    mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, j_mouse_handle, fractal);
    mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handle, fractal);
    mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask, j_mouse_move_handle, fractal);
}

int j_key_handle(int keysim, t_fractal *fractal)
{
    if (keysim == XK_Left)
        fractal->shift_x -= (0.5 * fractal->zoom);
    else if (keysim == XK_Right)
        fractal->shift_x += (0.5 * fractal->zoom);
    else if (keysim == XK_Up)
        fractal->shift_y += (0.5 * fractal->zoom);
    else if (keysim == XK_Down)
        fractal->shift_y -= (0.5 * fractal->zoom);
    else if (keysim == XK_Escape)
        close_handle(fractal);
    else if ((keysim == XK_minus) && (fractal->iterations >= 10))
        fractal->iterations -= 10;
    else if ((keysim == XK_space) && (fractal->iterations <= INT_MAX - 10))//XK_plus doesn't work
        fractal->iterations += 10;
    j_render(fractal);
    return (0);
}

int j_mouse_handle(int button, int x, int y, t_fractal *fractal)
{
    if (button == Button5)
    {
        fractal->zoom *= 0.95;
    }
    else if (button == Button4)
    {
        fractal->zoom *= 1.05;
    }
    j_render(fractal);
    return (0);
}

int    j_mouse_move_handle(int x, int y, t_fractal *fractal)
{ 
    fractal->julia_x = (scale(x, -2, +2, SCALE) * fractal->zoom) + fractal->shift_x;
    fractal->julia_y = (scale(y, 2, -2, SCALE) * fractal->zoom) + fractal->shift_y;
    j_render(fractal);
    return (0);
}
