/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:00 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:09:02 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_exit_help(void)
{
	ft_putstr_fd("\
The input is not correct. Provide the program with the following arguments:\n\
  * fractal name: 'mandelbrot', 'julia' and 'burning_ship' are supported\n\
  * If your choice is julia, then\n\
    - real C component (long double)\n\
    - imaginary C component (long double)\n\
  These components can be whatever whithin LDBL_MIN and LDBL_MAX,\n\
  but the fractal is beautiful when real and imaginary are between -1 and 1.\n\
  Some recommended values: 0.28 and 0.0113; -0.549653 and 0.003; -0.549653 and 0.003\n\
  * Size of display. Defined within unsigned int, but smth between 300 and 1000 is perfect\n\
  * Number of iterations for counting a point. Defined within int, but smth between 200 and 800 is perfect\n\
  You will be able to change the value when the program runs.\n\n\
Hotkeys:\n\
  * Left arrow - go left\n  * Right arrow - go right\n  * Up arrow - go up\n  * Down arrow - go up\n\
  * ESC - close fractal\n  * '+' - +10 iterations of point count\n  * '-' -10 iterations\n\
  * Scroll mouse - zoom in and zoom out\n\
  * 'z' - go to color change mode\n  * 'a' - return to preset color mode\n\
  * 's' - decrease color\n  * 'd' - increase color\n", 2);
	exit(EXIT_FAILURE);
}
