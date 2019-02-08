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
	int		floor;
	double	frac;
	double	num;
	double	den;

	if (n < 0)
		return ((int)index % 2 ? -ft_root(index, -n) : 0);
	floor = ft_floor(n);
	frac = n - floor;
	if (frac)
	{
		num = ft_root(index, ft_round(n / frac));
		den = ft_root(index, ft_round(1 / frac));
		return (num / den);
	}
	root = 0;
	while (root < n)
		if (ft_pow(root, index) != n)
			root++;
	return (root);
}