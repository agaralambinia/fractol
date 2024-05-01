/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:14:17 by defimova          #+#    #+#             */
/*   Updated: 2024/01/27 08:39:41 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
Аргументы:
s1, s2 – указатели на сравниваемые строки.
size_t n – количество символов для сравнения.

Возвращаемое значение:
0 – если первые n символов сравниваемых строк идентичны.

Положительное число – если в первых n символах сравниваемых строк есть отличия
и код первого отличающегося символа в строке s1 больше кода символа на той же
позиции в строке s2.

Отрицательное число – в первых n символах сравниваемых строк есть отличия
и код первого отличающегося символа в строке s1 меньше кода символа на той же
позиции в строке s2.
*/
/*
#include <stdio.h>
int	main()
{
	char s[] = "ft_strn456";
	char s2[] = "ft_strn789";
	printf("0 %d\n", ft_strncmp(s, s2, 3));
	printf("0 %d\n", ft_strncmp(s, s2, 7));
	printf("-3 %d\n", ft_strncmp(s, s2, 8));
	printf("3 %d\n", ft_strncmp(s2, s, 8));
	printf("-3 %d\n", ft_strncmp(s, s2, 10));
	printf("3 %d\n", ft_strncmp(s2, s, 10));
}
*/