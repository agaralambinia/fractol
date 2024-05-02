/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:07:39 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:07:42 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	main(int argc, char **argv)
{
	if ((argc == 4) && !(ft_strncmp(lower_char(argv[1]), "mandelbrot", 11)))
		ft_mandelbrot(argv);
	else if ((argc == 6) && !(ft_strncmp(lower_char(argv[1]), "julia", 6)))
		ft_julia(argv);
	else if (argc == 4 && !ft_strncmp(lower_char(argv[1]), "burning_ship", 14))
		ft_burning_ship(argv);
	else
		ft_exit_help();
}
