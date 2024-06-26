/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:11:28 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:11:29 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

char	*before_dot_ch(char *s)
{
	if ((((*s) > '9') || ((*s) < '0')) && !((*s) == '.'))
		ft_exit_error();
	return (s);
}

char	*after_dot_ch(char *s)
{
	if ((((*s) > '9') || ((*s) < '0')))
		ft_exit_error();
	return (s);
}

long double	ft_atod_val(int sign, char *s)
{
	long double	i;
	long		before_dot;
	long double	after_dot;

	i = 1.0;
	before_dot = 0;
	after_dot = 0;
	while (*s != '.' && *s)
	{
		before_dot_ch(s);
		before_dot = (before_dot * 10) + (*s++ - 48);
	}
	if (*s == '.')
		s++;
	while (*s)
	{
		i /= 10;
		after_dot_ch(s);
		after_dot = after_dot + ((*s++ - 48) * i);
	}
	return ((before_dot + after_dot) * sign);
}

long double	ft_atod(char *s)
{
	int			sign;

	sign = 1;
	while ((*s >= 9 && *s <= 13) || (*s == 32))
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1 * sign;
	}
	return (ft_atod_val(sign, s));
}
