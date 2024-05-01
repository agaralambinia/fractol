#include "../incs/fractol.h"

long double scale(long double unscaled, long double new_min, long double new_max, long double old_max)
{
    return ((new_max - new_min)*(unscaled) / old_max + new_min);
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}

t_complex square_complex(t_complex z)
{
    t_complex   result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}

t_complex abs_square_complex(t_complex z)
{
    t_complex   result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * fabsl(z.x * z.y);
    return (result);
}

char	*ft_tolower_char(char *c)
{
    int i;

    i = 0;
    while (c[i])
    {
	if (c[i] >= 65 && c[i] <= 90)
		c[i] += 32;
	i++;
    }
	return (c);
}