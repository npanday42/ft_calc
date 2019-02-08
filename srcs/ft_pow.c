/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 15:41:54 by npanday        #+#    #+#                */
/*   Updated: 2019/02/06 17:47:48 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_pow(double n, double pow)
{
	double	ret;
	int		floor;
	double	frac;
	int		num;
	int		den;

	if (n == 0 && pow != 0)
		return (0);
	if (pow < 0)
		return (1 / ft_pow(n, -pow));
	floor = ft_floor(pow);
	frac = pow - floor;
	if (frac)
	{
		num = pow / frac;
		den = 1 / frac;
		return (ft_root(den, ft_pow(n, num)));
	}
	ret = 1;
	while (pow > 0)
	{
		ret *= n;
		pow--;
	}
	return (ret);
}
