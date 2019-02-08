/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 11:53:15 by npanday        #+#    #+#                */
/*   Updated: 2019/02/07 11:53:15 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	expr(char *str);

static int		skip(const char *str)
{
	int i;
	int n;

	i = 1;
	n = 1;
	while (str[i] && n > 0)
	{
		if (str[i] == '(')
			n++;
		else if (str[i] == ')')
			n--;
		i++;
	}
	return (i - 1);
}

static double		factor(char *str) // # & ()
{
	char	c;
	int		end;

	c = *str;
	if (c == '-')
		return (-factor(str + 1));
	if (c == '(')
	{
		end = skip(str);
		str[end] = 0;
		return (expr(str + 1));
	}
	return (ft_atof(str));
}

static double		term(char *str, int end) // * & / & %
{
	int		i;
	char	c;

	i = 0;
	while (i < end)
	{
		c = str[i];
		if (c == '*')
			return (factor(str) * term(str + i + 1, end - i - 1));
		if (c == '/')
			return (factor(str) / term(str + i + 1, end - i - 1));
		if (c == '%')
			return ((int)factor(str) % (int)term(str + i + 1, end - i - 1)); 
		if (c == '!')
			return (ft_factorial(factor(str)));
		if (c == '^')
			return (ft_pow(factor(str), factor(str + i + 1)));
		if (c == '(')
			i += skip(str + i);
		i++;
	}
	return (factor(str));
}

static double		expr(char *str) // + & -
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c == '+')
			return (term(str, i) + expr(str + i + 1));
		if (c == '-' && i > 0)
			if (!ft_strchr("*/%!^", str[i - 1]))
				return (term(str, i) + expr(str + i));
		if (c == '(')
			i += skip(str + i);
		i++;
	}
	return (term(str, i));
}

double		ft_calc(const char *str)
{
	char 	*dup;

	dup = ft_strdup(str);
	return (str && dup ? expr(dup) : 0);
}
