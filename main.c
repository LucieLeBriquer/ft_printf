#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

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

void	test_errors_mac()
{
	int	res1;
	
	printt("[ 8 - TESTS SUR LES PCT ]");
	printst("%5%");
	res1 = ft_printf("[%5%]\n");
	printf("[    %%]\n");
	printf("mine = %d\twanted = %d\n", res1, 8);
	printst("%-5%");
	res1 = ft_printf("[%-5%]\n");
	printf("[%%    ]\n");
	printf("mine = %d\twanted = %d\n", res1, 8);
	printst("%05%");
	res1 = ft_printf("[%05%]\n");
	printf("[0000%%]\n");
	printf("mine = %d\twanted = %d\n", res1, 8);
	printst("%-05%");
	res1 = ft_printf("[%-05%]\n");
	printf("[%%    ]\n");
	printf("mine = %d\twanted = %d\n", res1, 8);
	
	printt("[ 1 - TESTS SUR LES STR ]");
	printst("%.03s  s = NULL");
	res1 = ft_printf("[%.03s]\n", NULL);
	printf("[(nu]\n");
	printf("mine = %d\twanted = %d\n", res1, 6);
	printst("%3.1s  s = NULL");
	res1 = ft_printf("[%3.1s]\n", NULL);
	printf("[  (]\n");
	printf("mine = %d\twanted = %d\n", res1, 6);
	printst("%9.1s  s = NULL");
	res1 = ft_printf("[%9.1s]\n", NULL);
	printf("[        (]\n");
	printf("mine = %d\twanted = %d\n", res1, 12);
	printst("%-3.1s  s = NULL");
	res1 = ft_printf("[%-3.1s]\n", NULL);
	printf("[(  ]\n");
	printf("mine = %d\twanted = %d\n", res1, 6);
	printst("%-9.1s  s = NULL");
	res1 = ft_printf("[%-9.1s]\n", NULL);
	printf("[(        ]\n");
	printf("mine = %d\twanted = %d\n", res1, 12);
	
	printt("[ 2 - TESTS SUR LES PTR ]");
	printst("%p  p = 0");
	res1 = ft_printf("[%p]\n", 0);
	printf("[0x0]\n");
	printf("mine = %d\twanted = %d\n", res1, 6);
	printst("%5p  p = 0");
	res1 = ft_printf("[%5p]\n", 0);
	printf("[  0x0]\n");
	printf("mine = %d\twanted = %d\n", res1, 8);
	printst("%.*p  p = 0  * = -3");
	res1 = ft_printf("[%.*p]\n", -3, 0);
	printf("[0x0]\n");
	printf("mine = %d\twanted = %d\n", res1, 6);
	printst("%.*p  p = 0  * = -1");
	res1 = ft_printf("[%.*p]\n", -1, 0);
	printf("[0x0]\n");
	printf("mine = %d\twanted = %d\n", res1, 6);
}

int		main()
{
	test_errors_mac();
/*	
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
	printst("-5c  c='\\x00'");
	res1 = ft_printf("[%-5c]\n", '\x00');
	res2 = printf("[%-5c]\n", '\x00');
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
	printst("2s  s=\"\"");
	res1 = ft_printf("[%2s]\n", "");
	res2 = printf("[%2s]\n", "");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("10.4s  s=ohayo");
	res1 = ft_printf("[%10.4s]\n", "ohayo");
	res2 = printf("[%10.4s]\n", "ohayo");
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("10.4s  s = NULL");
	res1 = ft_printf("[%10.4s]\n", NULL);
	res2 = printf("[%10.4s]\n", NULL);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("10s  s = NULL");
	res1 = ft_printf("[%10s]\n", NULL);
	res2 = printf("[%10s]\n", NULL);
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
	printst(".10p");
	res1 = ft_printf("[%.20p]\n", ptr);
	res2 = printf("[%.20p]\n", ptr);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("p  p = NULL");
	res1 = ft_printf("[%p]\n", NULL);
	res2 = printf("[%p]\n", NULL);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("p");
	res1 = ft_printf("[%p]\n", ptr);
	res2 = printf("[%p]\n", ptr);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("5p p = NULL");
	res1 = ft_printf("[%5p]\n", NULL);
	res2 = printf("[%5p]\n", NULL);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst(".0p p = NULL");
	res1 = ft_printf("[%.0p]\n", NULL);
	res2 = printf("[%.0p]\n", NULL);
	printf("mine = %d\torig = %d\n", res1, res2);
	
	printt("\n\n[ 3 - TESTS SUR LES INTD ]");
	printst("5d  d = 125");
	res1 = ft_printf("[%5d]\n", 125);
	res2 = printf("[%5d]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-5d  d = 125");
	res1 = ft_printf("[%-5d]\n", 125);
	res2 = printf("[%-5d]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("06.0d  d = -125");
	res1 = ft_printf("[%06.0d]\n", -125);
	res2 = printf("[%06.0d]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("06d  d = 125");
	res1 = ft_printf("[%06d]\n", 125);
	res2 = printf("[%06d]\n", 125);
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
	printst("d  d = int_max");
	res1 = ft_printf("[%d]\n", INT_MAX);
	res2 = printf("[%d]\n", INT_MAX);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("040d  d = int_min");
	res1 = ft_printf("[%040d]\n", INT_MIN);
	res2 = printf("[%040d]\n", INT_MIN);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("5.2d  d = 0");
	res1 = ft_printf("[%5.2d]\n", 0);
	res2 = printf("[%5.2d]\n", 0);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("5.d  d = 0");
	res1 = ft_printf("[%5.0d]\n", 0);
	res2 = printf("[%5.0d]\n", 0);
	printf("mine = %d\torig = %d\n", res1, res2);
	
	printt("\n\n[ 4 - TESTS SUR LES INTI ]");
	printst("-5i  i = 125");
	res1 = ft_printf("[%-5i]\n", 125);
	res2 = printf("[%-5i]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("06i  i = -125");
	res1 = ft_printf("[%06i]\n", -125);
	res2 = printf("[%06i]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-10.6i  i = -125");
	res1 = ft_printf("[%-10.6i]\n", -125);
	res2 = printf("[%-10.6i]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-10.2i  i = -125");
	res1 = ft_printf("[%-10.2i]\n", -125);
	res2 = printf("[%-10.2i]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("10.6i  i = -125");
	res1 = ft_printf("[%10.6i]\n", -125);
	res2 = printf("[%10.6i]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("6.10i  i = -125");
	res1 = ft_printf("[%6.10i]\n", -125);
	res2 = printf("[%6.10i]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("6.10d  d = 125456");
	res1 = ft_printf("[%6.10d]\n", 125456);
	res2 = printf("[%6.10d]\n", 125456);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst(".2i  i = -125");
	res1 = ft_printf("[%.2i]\n", -125);
	res2 = printf("[%.2i]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst(".2i  i = -125");
	res1 = ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	res2 = printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	printf("mine = %d\torig = %d\n", res1, res2);

	printt("\n\n[ 5 - TESTS SUR LES UNSIGNED ]");
	printst("-5u  u = 125");
	res1 = ft_printf("[%-5u]\n", 125);
	res2 = printf("[%-5u]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("05u  u = -125");
	res1 = ft_printf("[%05u]\n", -125);
	res2 = printf("[%05u]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("020u  u = uintmax");
	res1 = ft_printf("[%020u]\n", UINT_MAX);
	res2 = printf("[%020u]\n", UINT_MAX);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-20u  u = uintmax");
	res1 = ft_printf("[%-20u]\n", UINT_MAX);
	res2 = printf("[%-20u]\n", UINT_MAX);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-10.6u  u = -125");
	res1 = ft_printf("[%-10.6u]\n", -125);
	res2 = printf("[%-10.6u]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-10.2u  u = 125456");
	res1 = ft_printf("[%-10.2u]\n", 125456);
	res2 = printf("[%-10.2u]\n", 125456);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("10.6u  u = 125456");
	res1 = ft_printf("[%10.6u]\n", 125456);
	res2 = printf("[%10.6u]\n", 125456);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("6.10i  i = 125456");
	res1 = ft_printf("[%6.10u]\n", 125456);
	res2 = printf("[%6.10u]\n", 125456);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst(".2u  u = 125");
	res1 = ft_printf("[%.2u]\n", 125);
	res2 = printf("[%.2u]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	
	printt("\n\n[ 6 - TESTS SUR LES INT hex ]");
	printst("-5x  x = 125");
	res1 = ft_printf("[%-5x]\n", 125);
	res2 = printf("[%-5x]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-5x  x = -125");
	res1 = ft_printf("[%-5x]\n", -125);
	res2 = printf("[%-5x]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);

	printt("\n\n[ 7 - TESTS SUR LES INT HEX ]");
	printst("-5X  X = 125");
	res1 = ft_printf("[%-5X]\n", 125);
	res2 = printf("[%-5X]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("-5X  X = -125");
	res1 = ft_printf("[%-5X]\n", -125);
	res2 = printf("[%-5X]\n", -125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst(" -5X  X = 125");
	res2 = printf("[% -5X]\n", 125);
	res1 = ft_printf("[% -5X]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	printst("    -5X  X = 125");
	res2 = printf("[%    -5X]\n", 125);
	res1 = ft_printf("[%    -5X]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	
	printt("\n\n[ 8 - TESTS SUR LES PCT ]");
	printst("\%\%");
	res1 = ft_printf("[%%]\n", 125);
	res2 = printf("[%%]\n", 125);
	printf("mine = %d\torig = %d\n", res1, res2);
	*/
	return (0);
}
