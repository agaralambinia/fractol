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
	fractal.iter = ft_atoui(args[3]);
	fractal_init(&fractal);
	bs_events_init(&fractal);
	data_init(&fractal);
	bs_render(&fractal);
	mlx_loop(fractal.mlx_con);
}

void	bs_render(t_fractal *f)
{
	unsigned int	x;
	unsigned int	y;

	y = 1;
	while (y++ < f->scale)
	{
		x = 1;
		while (x++ < f->scale)
			bs_pixel(x, y, f);
	}
	mlx_put_image_to_window(f->mlx_con, f->mlx_w, f->img.img_p, 0, 0);
}

void	bs_pixel(int x, int y, t_fractal *f)
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
		z = sum_complex(abs_square_complex(z), c);
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
