#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <math.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include "../../../minilbx/mlx.h"


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
	long double zoom;
	long double	julia_x;
	long double	julia_y;
}   t_fractal;

void    	ft_mandelbrot(void);
void    	m_pixel(int x, int y, t_fractal *fractal);
void    	m_render(t_fractal *fractal);
void		m_events_init(t_fractal *fractal);
int 		m_key_handle(int keysim, t_fractal *fractal);
int 		m_mouse_handle(int button, int x, int y, t_fractal *fractal);

void    	ft_julia(char *real, char *i);
void    	j_pixel(int x, int y, t_fractal *fractal);
void    	j_render(t_fractal *fractal);
void 		j_events_init(t_fractal *fractal);
int 		j_key_handle(int keysim, t_fractal *fractal);
int 		j_mouse_handle(int button, int x, int y, t_fractal *fractal);
int    		j_mouse_move_handle(int x, int y, t_fractal *fractal);

void    	ft_burning_ship(void);
void    	bs_pixel(int x, int y, t_fractal *fractal);
void    	bs_render(t_fractal *fractal);
void 		bs_events_init(t_fractal *fractal);
int			bs_key_handle(int keysim, t_fractal *fractal);
int 		bs_mouse_handle(int button, int x, int y, t_fractal *fractal);

void		ft_exit_error(void);
void 		data_init(t_fractal *fractal);
void    	fractal_init(t_fractal *fractal);
int    		close_handle(t_fractal *fractal);
void    	pixel_draw(int x, int y, t_img *img, int color);

long double	scale(long double unscaled, long double new_min, long double new_max, long double old_max);
t_complex 	sum_complex(t_complex z1, t_complex z2);
t_complex 	square_complex(t_complex z);
t_complex 	abs_square_complex(t_complex z);

int			isspace_check(const char a);
long double	ft_atod(char *s);
int			ft_sign(char *s);
char 		*before_dot_ch(char *s);
char 		*after_dot_ch(char *s);
char		*ft_tolower_char(char *c);

#endif