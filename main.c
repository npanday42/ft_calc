#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	prompt(void)
{
	char 	str[BUFF_SIZE];
	double	ans;
	time_t 	start;
	time_t	sstart;
	time_t 	end;

	time(&sstart);
	while(printf("> "))
	{
		scanf("%s", str);
		if (!ft_strcmp(str, "exit"))
			break;
		else
		{
			time(&start);
			ans = ft_calc(str);
			time(&end);
			printf(" = %g\n", ans);
			printf("time: %g\n", difftime(end, start));
		}
	}
	time(&end);
	printf("Exiting...\ntime: %f\n", difftime(end, sstart));
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