#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //TODO debug
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include "minilbx/mlx.h"


#define WIDTH 800 //TODO
#define HEIGHT 800

#define BLACK       0x000000
#define WHITE       0xFFFFFF
#define RED         0xFF0000
#define GREEN       0x00FF00
#define BLUE        0x0000FF
#define MAGENTA_BURST   0xFF00FF
#define LIME_SHOCK      0xCCFF00 
#define NEON_ORANGE     0xFF6600
#define PSYCHEDELIC_PURPLE 0x660066
#define AQUA_DREAM      0x33CCCC
#define HOT_PINK        0xFF66B2
#define ELECTRIC_BLUE   0x0066FF
#define LAVA_RED        0xFF3300

typedef struct	s_complex
{
	long double x;
	long double y;
}   t_complex;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}   t_img;

typedef struct s_fractal
{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
	t_img	img;
	long double hipotenuse;
	int	iterations;
	long double shift_x;
	long double shift_y;
}   t_fractal;

void	ft_exit_error(void);
long double scale(long double unscaled, long double new_min, long double new_max, long double old_max);
void    handle_pixel(int x, int y, t_fractal *fractal);
void    fractal_render(t_fractal *fractal);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);
void data_init(t_fractal *fractal);
void    fractal_init(t_fractal *fractal);
void events_init(t_fractal *fractal);
int key_handle(int keysim, t_fractal *fractal);
int    close_handle(t_fractal *fractal);
int mouse_handle(int button, int x, int y, t_fractal *fractal);

#endif