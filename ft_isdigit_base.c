/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/09 16:19:30 by npanday        #+#    #+#                */
/*   Updated: 2019/03/09 16:19:30 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calc.h"

int			ft_isdigit_base(char c, unsigned int base)
{
	if (base == 1)
		return (c == '1');
	else if (base <= 16)
		return ((ft_strchr(ft_strndup(DIGITS, base), c)));
	else
		return (0);
}
