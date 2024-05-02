/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_burning_ship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:06:48 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:06:49 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	ft_burning_ship(char **args)
{
	t_fractal	fractal;

	fractal.name = "burning_ship";
	fractal.scale = ft_atoui(args[2]);
	fractal.iterations = ft_atoui(args[3]);
	fractal_init(&fractal);
	bs_events_init(&fractal);
	data_init(&fractal);
	bs_render(&fractal);
	mlx_loop(fractal.mlx_connection);
}

void	bs_render(t_fractal *fractal)
{
	unsigned int	x;
	unsigned int	y;

	y = 1;
	while (y++ < fractal->scale)
	{
		x = 1;
		while (x++ < fractal->scale)
			bs_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, \
		fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

void	bs_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (scale(x, -2, 2, fractal->scale) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, 2, -2, fractal->scale) * fractal->zoom) + fractal->shift_y;
	c.x = z.x;
	c.y = z.y;
	while (i < fractal->iterations)
	{
		z = sum_complex(abs_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->hipotenuse)
		{
			color = scale(i, fractal->min_color, \
				fractal->max_color, fractal->iterations);
			pixel_draw(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	pixel_draw(x, y, &fractal->img, fractal->max_color);
}
