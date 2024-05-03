/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mandelbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:07:21 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:07:25 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	ft_mandelbrot(char **args)
{
	t_fractal	fractal;

	fractal.name = "mandelbrot";
	fractal.scale = ft_atoui(args[2]);
	fractal.iter = ft_atoi(args[3]);
	fractal_init(&fractal);
	m_events_init(&fractal);
	data_init(&fractal);
	m_render(&fractal);
	mlx_loop(fractal.mlx_con);
}

void	m_render(t_fractal *f)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y++ < f->scale)
	{
		x = 0;
		while (x++ < f->scale)
			m_pixel(x, y, f);
	}
	mlx_put_image_to_window(f->mlx_con, f->mlx_w, f->img.img_p, 0, 0);
}

void	m_pixel(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (scale(x, -2, 2, f->scale) * f->zoom) + f->shift_x;
	z.y = (scale(y, 2, -2, f->scale) * f->zoom) + f->shift_y;
	c.x = z.x;
	c.y = z.y;
	while (i < f->iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->hipotenuse)
		{
			color = scale(i, f->min_color, f->max_color, f->iter);
			pixel_draw(x, y, f, color);
			return ;
		}
		i++;
	}
	pixel_draw(x, y, f, f->max_color);
}
