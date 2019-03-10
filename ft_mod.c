/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mod.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/10 20:02:50 by npanday        #+#    #+#                */
/*   Updated: 2019/03/10 20:02:50 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calc.h"

int			ft_mod(int num, int den)
{
	if (num < 0)
		return (-ft_mod(-num, den));
	if (den < 0)
		return (-ft_mod(num, -den));
	return (num - num / den * den);
}
