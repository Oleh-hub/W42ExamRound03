#include <stdio.h>  // printf
#include <limits.h>  // INT_MIN, INT_MAX
#define P k += printf
#define A k += ft_printf

int ft_printf(const char *str, ...);

int main(void)
{
	int k = 0;
	
	P("");
	P("\n");
	P("abcd4321\\\n");
	P("abcd4321\\%%%%\n");
	P("%s\n", "jjlmn");
	P("%s\n", "");
	P("%s\n", NULL);
	P("\n");
	P("%d\n", 0);
	P("%d\n", INT_MIN);
	P("%d\n", INT_MAX);
	P("\n");
	P("%x\n", 0);
	P("%x\n", 999);
	P("%x\n", INT_MAX);
	printf("Total printed out %d characters\n", k);
	
	k = 0;

	A("");
	A("\n");
	A("abcd4321\\\n");
	A("abcd4321\\%%%%\n");
	A("%s\n", "jjlmn");
	A("%s\n", "");
	A("%s\n", NULL);
	A("\n");
	A("%d\n", 0);
	A("%d\n", INT_MIN);
	A("%d\n", INT_MAX);
	A("\n");
	A("%x\n", 0);
	A("%x\n", 999);
	A("%x\n", INT_MAX);
	printf("Total printed out %d characters\n", k);
}