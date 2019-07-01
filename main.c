/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 13:51:43 by npanday        #+#    #+#                */
/*   Updated: 2019/07/01 13:36:43 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calc.h"

void	prompt(void)
{
	char	*line;
	double	ans;
	time_t	start;
	time_t	end;

	while (printf("> "))
	{
		get_next_line(0, &line);
		if (ft_strcmp(line, "exit") == 0)
			break ;
		else
		{
			time(&start);
			ans = ft_calc(line);
			time(&end);
			printf(" = %g\n", ans);
			printf("time: %g\n", difftime(end, start));
		}
	}
	printf("Exiting...\n");
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("%g\n", ft_calc(argv[1]));
	else if (argc == 1)
		prompt();
	else
		return (0);
	return (1);
}
