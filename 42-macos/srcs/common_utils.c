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
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
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

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		ft_exit_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, \
		fractal->scale, fractal->scale, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		free(fractal->mlx_connection);
		ft_exit_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, \
		fractal->scale, fractal->scale);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		ft_exit_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, \
		&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}

void	pixel_draw(int x, int y, t_img *img, int color)
{
	char	*dst;

	dst = img->pixels_ptr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	change_color(t_fractal *fractal, int keysim)
{
	if (keysim == 0)
	{
		fractal->min_color = 0;
		fractal->max_color = 16777215;
	}
	else if (keysim == 6)
	{
		fractal->min_color = 3394764;
		fractal->max_color = 13434624;
	}
	else if ((keysim == 1) && (fractal->min_color >= 10000))
	{
		fractal->min_color -= 10000;
		fractal->max_color -= 10000;
	}
	else if ((keysim == 2) && (fractal->max_color <= 16767215))
	{
		fractal->min_color += 10000;
		fractal->max_color += 10000;
	}
}
