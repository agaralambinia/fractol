/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:06:30 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:06:33 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_con, fractal->img.img_p);
	mlx_destroy_window(fractal->mlx_con, fractal->mlx_w);
	free(fractal->mlx_con);
	exit(EXIT_SUCCESS);
}

void	data_init(t_fractal *fractal)
{
	fractal->hipotenuse = 4;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->min_color = 0;
	fractal->max_color = 16777215;
}

void	fractal_init(t_fractal *f)
{
	f->mlx_con = mlx_init();
	if (f->mlx_con == NULL)
		ft_exit_error();
	f->mlx_w = mlx_new_window(f->mlx_con, f->scale, f->scale, f->name);
	if (f->mlx_w == NULL)
	{
		free(f->mlx_con);
		ft_exit_error();
	}
	f->img.img_p = mlx_new_image(f->mlx_con, f->scale, f->scale);
	if (f->img.img_p == NULL)
	{
		mlx_destroy_window(f->mlx_con, f->mlx_w);
		free(f->mlx_con);
		ft_exit_error();
	}
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_p, \
		&f->img.bpp, &f->img.line_len, &f->img.endian);
}

void	pixel_draw(int x, int y, t_fractal *f, int color)
{
	if (x >= 0 && y >= 0 && x < (int)f->scale && y < (int)f->scale)
	{
		f->img.pixels_ptr[(x * f->img.bpp >> 3) \
			+ (y * f->img.line_len)] = color % 256;
		f->img.pixels_ptr[(x * f->img.bpp >> 3) \
			+ (y * f->img.line_len + 1)] = ((color % 65536) / 256);
		f->img.pixels_ptr[(x * f->img.bpp >> 3) \
			+ (y * f->img.line_len + 2)] = (color / 65536);
	}
}

void	change_color(t_fractal *fractal, int k)
{
	if (k == 38)
	{
		fractal->min_color = 0;
		fractal->max_color = 16777215;
	}
	else if (k == 4)
	{
		fractal->min_color = 3394764;
		fractal->max_color = 13434624;
	}
	else if ((k == 40) && (fractal->min_color >= 10000))
	{
		fractal->min_color -= 10000;
		fractal->max_color -= 10000;
	}
	else if ((k == 37) && (fractal->max_color <= 16767215))
	{
		fractal->min_color += 10000;
		fractal->max_color += 10000;
	}
}
