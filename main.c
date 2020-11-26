#include "ft_printf.h"

#define white "\033[0m"
#define cyanB "\033[1;36m"
#define cyan "\033[36m"
#define couleur(param) printf("\033[%sm", param)
#define endcouleur printf("\033[0m")

/*
 * 30 Noir		31 Rouge	32 Vert		33 Jaune	34 Bleu
 * 35 Magenta	36 Cyan 	37 Blanc
 */

void	printt(char *str)
{
	printf("%s%s%s\n", cyanB, str, white);
}

void	printst(char *str)
{
	printf("\n%s>>> pour %s%s\n", cyan, str, white);
}

int		main()
{
	int res1;
	int res2;

	printt("[ TESTS SUR LES STRINGS ]");
	printst("-2s");
	res1 = ft_printf("[%-2s]\n", "bonjour");
	res2 = printf("[%-2s]\n", "bonjour");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-10.5s");
	res1 = ft_printf("[%-10.5s]\n", "ohayo");
	res2 = printf("[%-10.5s]\n", "ohayo");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("1.2s");
	res1 = ft_printf("[%1.2s]\n", "plop");
	res2 = printf("[%1.2s]\n", "plop");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("*s *=-12");
	res1 = ft_printf("[%*s]\n", -12, "plop");
	res2 = printf("[%*s]\n", -12, "plop");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst(".*s *=-12");
	res1 = ft_printf("[%.*s]\n", -12, "plop");
	res2 = printf("[%.*s]\n", -12, "plop");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("s s=\"\"");
	res1 = ft_printf("[%s]\n", "");
	res2 = printf("[%s]\n", "");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("10.4s");
	res1 = ft_printf("[%10.4s]\n", "ohayo");
	res2 = printf("[%10.4s]\n", "ohayo");
	printf("mine = %d\torig = %d\n", res1, res2);
	return (0);
}
