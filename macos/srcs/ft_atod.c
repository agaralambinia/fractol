#include "../incs/fractol.h"

char *before_dot_ch(char *s)
{
    if ((((*s) > '9') || ((*s) < '0')) && !((*s) == '.'))
        ft_exit_error();
    return (s);
}

char *after_dot_ch(char *s)
{
    if ((((*s) > '9') || ((*s) < '0')))
        ft_exit_error();
    return (s);
}

int	ft_sign(char *s)
{
	int	sign;

	sign = 1;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1 * sign;
	}
	return (sign);
}

long double	ft_atod(char *s)
{
	long	before_dot;
	long double	after_dot;
	long double	i;
	int			sign;

	before_dot = 0;
	after_dot = 0;
	i = 1;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || (*s == 32))
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1 * sign;
	}
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