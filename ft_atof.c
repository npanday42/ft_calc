/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:17:38 by npanday        #+#    #+#                */
/*   Updated: 2019/02/07 14:17:38 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calc.h"

double		ft_atof(const char *str)
{
	return (ft_atof_base(str, 10));
}
