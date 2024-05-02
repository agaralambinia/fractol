/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:08:19 by defimova          #+#    #+#             */
/*   Updated: 2024/05/02 15:08:20 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

char	*lower_char(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= 65 && c[i] <= 90)
			c[i] += 32;
		i++;
	}
	return (c);
}

int	ft_atoui(const char *str)
{
	int				i;
	unsigned int	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32) || (str[i] == 43))
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			ft_exit_help();
		res = res * 10 - 48 + str[i];
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = (-1) * sign;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			ft_exit_help();
		res = res * 10 - 48 + str[i];
		i++;
	}
	return (res * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	i = 0;
	if (!ss1 && !ss2)
		return (0);
	while ((ss1[i] || ss2[i]) && (i < n))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
