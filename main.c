#include "ft_calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	prompt(void)
{
	char 	str[BUFF_SIZE];
	double	ans;
	time_t 	start;
	time_t 	end;

	while(printf("> "))
	{
		scanf("%s", str);
		if (ft_strcmp(str, "exit") == 0)
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
	printf("Exiting...\n");
}

int		main(int argc, char **argv)
{
	time_t	start;
	time_t	end;

	if (argc == 2)
	{
		time(&start);
		printf("%g\n", ft_calc(argv[1]));
		time(&end);
		printf("time: %g\n", difftime(end, start));
	}
	else if (argc == 1)
		prompt();
	else
		return (0);
	return (1);
}