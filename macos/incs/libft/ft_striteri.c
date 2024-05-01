/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:02:04 by defimova          #+#    #+#             */
/*   Updated: 2024/01/21 21:03:28 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
Аргументы:
s: Строка, по которой выполняется итерация.
f: Функция, применяемая к каждому символу.

Возвращаемое значение: нет

Описание:
Применяет функцию ’f’ к каждому символу
строки, передаваемой в качестве аргумента, передавая ее индекс
в качестве первого аргумента. Каждый символ передается по
адресу в ’f’, символ при необходимости может быть изменен.
*/