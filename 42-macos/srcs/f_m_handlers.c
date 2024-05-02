/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_m_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:34:15 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:34:17 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	m_events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, m_key_handle, fractal);
	mlx_mouse_hook(fractal->mlx_window, m_mouse_handle, fractal);
}

int	m_key_handle(int keysim, t_fractal *fractal)
{
	if (keysim == 37)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysim == 39)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysim == 38)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysim == 40)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysim == 53)
		close_handle(fractal);
	else if ((keysim == 27) && (fractal->iterations >= 10))
		fractal->iterations -= 10;
	else if ((keysim == 49) \
		&& (fractal->iterations <= INT_MAX - 10))
		fractal->iterations += 10;
	else if (keysim == 0 || keysim == 6 || keysim == 1 || keysim == 2 || keysim == 35)
		change_color(fractal, keysim);
	m_render(fractal);
	return (0);
}

int	m_mouse_handle(int button, int x, int y, t_fractal *fractal)
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
	m_render(fractal);
	return (0);
}
