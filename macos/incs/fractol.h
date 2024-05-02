#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <math.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../../../minilbx/mlx.h"

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
    char    		*name;
    void    		*mlx_connection;
    void    		*mlx_window;
	t_img			img;
	long double 	hipotenuse;
	int				iterations;
	long double 	shift_x;
	long double 	shift_y;
	long double 	zoom;
	long double		julia_x;
	long double		julia_y;
	unsigned int	scale;
	int				min_color;
	int				max_color;
}   t_fractal;

void    	ft_mandelbrot(char **args);
void    	m_pixel(int x, int y, t_fractal *fractal);
void    	m_render(t_fractal *fractal);
void		m_events_init(t_fractal *fractal);
int 		m_key_handle(int keysim, t_fractal *fractal);
int 		m_mouse_handle(int button, int x, int y, t_fractal *fractal);

void    	ft_julia(char **args);
void    	j_pixel(int x, int y, t_fractal *fractal);
void    	j_render(t_fractal *fractal);
void 		j_events_init(t_fractal *fractal);
int 		j_key_handle(int keysim, t_fractal *fractal);
int 		j_mouse_handle(int button, int x, int y, t_fractal *fractal);
int    		j_mouse_move_handle(int x, int y, t_fractal *fractal);

void    	ft_burning_ship(char **args);
void    	bs_pixel(int x, int y, t_fractal *fractal);
void    	bs_render(t_fractal *fractal);
void 		bs_events_init(t_fractal *fractal);
int			bs_key_handle(int keysim, t_fractal *fractal);
int 		bs_mouse_handle(int button, int x, int y, t_fractal *fractal);

void		ft_exit_error(void);
void		ft_exit_help(void);
void 		data_init(t_fractal *fractal);
void    	fractal_init(t_fractal *fractal);
int    		close_handle(t_fractal *fractal);
void    	pixel_draw(int x, int y, t_img *img, int color);
void		change_color(t_fractal *fractal, int keysim);

long double	scale(long double unscaled, long double new_min, long double new_max, long double old_max);
t_complex 	sum_complex(t_complex z1, t_complex z2);
t_complex 	square_complex(t_complex z);
t_complex 	abs_square_complex(t_complex z);

int			isspace_check(const char a);
long double	ft_atod(char *s);
int			ft_sign(char *s);
char 		*before_dot_ch(char *s);
char 		*after_dot_ch(char *s);
char		*ft_to_lower_char(char *c);
int			ft_atoi(const char *str);
int			ft_atoui(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
#endif