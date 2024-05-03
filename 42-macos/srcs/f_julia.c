/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:07:04 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:07:06 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	ft_julia(char **args)
{
	t_fractal	fractal;

	fractal.name = "julia";
	fractal.scale = ft_atoui(args[4]);
	fractal.iter = ft_atoi(args[5]);
	fractal.julia_x = ft_atod(args[2]);
	fractal.julia_y = ft_atod(args[3]);
	printf("%Lf, %Lf\n", fractal.julia_x, fractal.julia_y);
	fractal_init(&fractal);
	j_events_init(&fractal);
	data_init(&fractal);
	j_render(&fractal);
	mlx_loop(fractal.mlx_con);
}

void	j_render(t_fractal *f)
{
	unsigned int	x;
	unsigned int	y;

	y = 1;
	while (y++ < f->scale)
	{
		x = 1;
		while (x++ < f->scale)
			j_pixel(x, y, f);
	}
	mlx_put_image_to_window(f->mlx_con, f->mlx_w, f->img.img_p, 0, 0);
}

void	j_pixel(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (scale(x, -2, 2, f->scale) * f->zoom) + f->shift_x;
	z.y = (scale(y, 2, -2, f->scale) * f->zoom) + f->shift_y;
	c.x = f->julia_x;
	c.y = f->julia_y;
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
