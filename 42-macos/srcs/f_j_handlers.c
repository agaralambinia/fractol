/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_j_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:51:03 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:51:04 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	j_events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_w, j_key_handle, fractal);
	mlx_mouse_hook(fractal->mlx_w, j_mouse_handle, fractal);
	mlx_hook(fractal->mlx_w, 17, 0, close_handle, fractal);
}

int	j_key_handle(int k, t_fractal *fractal)
{
	if (k == 0)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (k == 2)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (k == 13)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (k == 1)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (k == 53)
		close_handle(fractal);
	else if ((k == 31) && (fractal->iter >= 10))
		fractal->iter -= 10;
	else if ((k == 35) && (fractal->iter <= INT_MAX - 10))
		fractal->iter += 10;
	else
		change_color(fractal, k);
	j_render(fractal);
	return (0);
}

int	j_mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == 4)
	{
		fractal->zoom *= 1.05;
	}
	j_render(fractal);
	return (0);
}
