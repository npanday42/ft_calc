/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calc.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/07 16:28:33 by npanday        #+#    #+#                */
/*   Updated: 2019/03/07 16:28:33 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CALC_H
# define FT_CALC_H
# include "libft/libft.h"

double		ft_atof(const char *str);
double		ft_atof_base(const char *str, unsigned int b);
double		ft_calc(const char *str);
int			ft_mod(int num, int den);
#endif
