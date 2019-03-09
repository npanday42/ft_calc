/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/09 16:48:37 by npanday        #+#    #+#                */
/*   Updated: 2019/03/09 16:48:37 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calc.h"

static char		*skip(const char *str, unsigned int b)
{
	char	*start;

	if (!str || !b || b > 10)
		return (NULL);
	start = (char *)str;
	while (ft_isspace(*start))
		start++;
	if (!ft_isdigit_base(start[0], b))
	{
		if (ft_strchr("+-", start[0]))
			if (ft_isdigit_base(start[1], b))
				return (start);
		return (NULL);
	}
	return (start);
}

static int		sign(const char *str, unsigned int b)
{
	if (*str == '-')
		return (-1 * ft_atof_base(str + 1, b));
	else if (*str == '+')
		return (ft_atof_base(str + 1, b));
	else
		return (0);
}

static double	mantissa(double ret, char *a, char c)
{
	while (*a != c)
	{
		ret /= 10;
		a--;
	}
	return (ret);
}

double			ft_atof_baseb(const char *str, unsigned int b)
{
	int		ret;
	char	*a;
	char	c;
	char	*digits;

	a = skip(str, b);
	if (!a)
		return (0);
	digits = ft_strndup(DIGITS, b);
	if (!ft_isdigit_base(*a, b))
		return (sign(a, b));
	c = 0;
	ret = 0;
	while (*a && ft_isdigit_base(*a, b))
	{
		ret *= b;
		ret += ft_strchr(digits, *a) - digits;
		a += !(c);
		if (!c)
			if (ft_strchr(",.", a[1]))
				c = a[1];
		a += (c);
	}
	return (c ? mantissa(ret, a - 1, c) : ret);
}
