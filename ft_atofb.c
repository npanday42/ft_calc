/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atofb.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:58:53 by npanday        #+#    #+#                */
/*   Updated: 2019/02/07 13:58:53 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calc.h"

static int	sign(const char *str, unsigned int b)
{
	if (*str == '-')
		return (-1 * ft_atofb(str + 1, b));
	else if (*str == '+')
		return (ft_atofb(str + 1, b));
	else
		return (0);
}

static char	*skip(const char *str, unsigned int b)
{
	char	*start;

	if (!str || !b || b > 10)
		return (NULL);
	start = (char *)str;
	while (ft_isspace(*start))
		start++;
	if (!ft_isdigit(start[0]) && ft_isdigit(start[1]))
		if (start[0] == '+' || start[0] == '-')
			return (start);
	return (ft_isdigit(start[0]) ? start : NULL);
}

double		f(double ret, char *a)
{
	while (*a != '.')
	{
		ret /= 10;
		a--;
	}
	return (ret);
}

double		ft_atofb(const char *str, unsigned int b)
{
	int		ret;
	char	*a;
	int		c;

	a = skip(str, b);
	if (!a)
		return (0);
	if (!ft_isdigit(*a))
		return (sign(a, b));
	c = 0;
	ret = 0;
	while (*a && ft_isdigit(*a))
	{
		if (b != 1 && *a - '0' >= (int)b)
			return (0);
		ret *= b;
		ret += *a - '0';
		if (a[1] == '.' && !c)
		{
			c = 1;
			a++;
		}
		a++;
	}
	return (c ? f(ret, a - 1) : ret);
}
