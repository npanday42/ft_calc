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

#include "ft_calc.h"

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

static double		factor(char *str)
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

static double		term(char *str, int end)
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

double		ft_calc(const char *str)
{
	char 	*expr;
	int		i;
	char	c;

	expr = ft_strdup(str);
	if (!expr)
		return (0);
	i = 0;
	while (expr[i])
	{
		c = expr[i];
		if (c == '+')
			return (term(expr, i) + ft_calc(expr + i + 1));
		if (c == '-' && i > 0)
			if (!ft_strchr("*/%!^", expr[i - 1]))
				return (term(expr, i) + ft_calc(expr + i));
		if (c == '(')
			i += skip(expr + i);
		i++;
	}
	return (term(expr, i));
}
