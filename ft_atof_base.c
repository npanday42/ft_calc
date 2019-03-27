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

	if (!str || !b || b > 16)
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

static double	itof(double ret, char *a, char c)
{
	a--;
	while (*a != c)
	{
		ret /= 10;
		a--;
	}
	return (ret);
}

double			ft_atof_base(const char *str, unsigned int b)
{
	char	*digits;
	char	*a;
	int		ret;
	char	c;

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
		a += c ? 0 : 1;
		if (c == 0)
			if (ft_strchr(",.", *a))
				c = *a;
		a += c ? 1 : 0;
	}
	return (c ? itof(ret, a, c) : ret);
}
