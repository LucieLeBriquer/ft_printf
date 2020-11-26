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
	int	*ptr;
	
	ptr = &res1;
	
	printt("[ 0 - TESTS SUR LES CHAR ]");
	printst("6c  c='a'");
	res1 = ft_printf("[%6c]\n", 'a');
	res2 = printf("[%6c]\n", 'a');
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-6c  c='a'");
	res1 = ft_printf("[%-6c]\n", 'a');
	res2 = printf("[%-6c]\n", 'a');
	printf("mine = %d\torig = %d\n", res1, res2);

	printt("\n\n[ 1 - TESTS SUR LES STRINGS ]");
	printst("-2s  s=bonjour");
	res1 = ft_printf("[%-2s]\n", "bonjour");
	res2 = printf("[%-2s]\n", "bonjour");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-10.5s  s=ohayo");
	res1 = ft_printf("[%-10.5s]\n", "ohayo");
	res2 = printf("[%-10.5s]\n", "ohayo");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("1.2s  s=plop");
	res1 = ft_printf("[%1.2s]\n", "plop");
	res2 = printf("[%1.2s]\n", "plop");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("*s *=-12  s=plop");
	res1 = ft_printf("[%*s]\n", -12, "plop");
	res2 = printf("[%*s]\n", -12, "plop");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst(".*s *=-12  s=plop");
	res1 = ft_printf("[%.*s]\n", -12, "plop");
	res2 = printf("[%.*s]\n", -12, "plop");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("s  s=\"\"");
	res1 = ft_printf("[%s]\n", "");
	res2 = printf("[%s]\n", "");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("10.4s  s=ohayo");
	res1 = ft_printf("[%10.4s]\n", "ohayo");
	res2 = printf("[%10.4s]\n", "ohayo");
	printf("mine = %d\torig = %d\n", res1, res2);
	
	printt("\n\n[ 2 - TESTS SUR LES POINTEURS ]");
	printst("-30p");
	res1 = ft_printf("[%-30p]\n", ptr);
	res2 = printf("[%-30p]\n", ptr);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("40p");
	res1 = ft_printf("[%40p]\n", ptr);
	res2 = printf("[%40p]\n", ptr);
	printf("mine = %d\torig = %d\n", res1, res2);
	/* pas de precision sur les pointeurs */
	
	printt("\n\n[ 3 - TESTS SUR LES INTD ]");
	printst("-5d  d = 125");
	res1 = ft_printf("[%-5d]\n", 125);
	res2 = printf("[%-5d]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("06d  d = -125");
	res1 = ft_printf("[%06d]\n", -125);
	res2 = printf("[%06d]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-10.6d  d = -125");
	res1 = ft_printf("[%-10.6d]\n", -125);
	res2 = printf("[%-10.6d]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-10.2d  d = -125");
	res1 = ft_printf("[%-10.2d]\n", -125);
	res2 = printf("[%-10.2d]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("10.6d  d = -125");
	res1 = ft_printf("[%10.6d]\n", -125);
	res2 = printf("[%10.6d]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("6.10d  d = -125");
	res1 = ft_printf("[%6.10d]\n", -125);
	res2 = printf("[%6.10d]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst(".2d  d = -125");
	res1 = ft_printf("[%.2d]\n", -125);
	res2 = printf("[%.2d]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	
	return (0);
}
