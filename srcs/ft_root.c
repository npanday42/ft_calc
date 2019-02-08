/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_root.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 16:07:11 by npanday        #+#    #+#                */
/*   Updated: 2019/02/06 18:00:56 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_root(unsigned int index, double n)
{
	int		root;
	double	frac;
	int		num;
	int		den;

	if (n < 0)
		return ((int)index % 2 ? -ft_root(index, -n) : 0);
	frac = n - ft_floor(n);
	if (frac)
	{
		frac = frac > 0.5 ? 1 - frac : frac;
		num = ft_round(n / frac);
		den = ft_round(1 / frac);
		return (ft_root(index, num) / ft_root(index, den));
	}
	frac = 0;
	root = 0;
	while (TRUE)
	{
		frac = root && n <= index ? (root + 1) / root : root;
		frac = root ? ft_pow(frac, index) : 0;
		if (frac == n)
			break ;
		root++;
	}
	return (root);
}