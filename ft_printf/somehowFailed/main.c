// JCluzet's code from 42_EXAM
// pefercly full check of ft_printf for %d, %c, %x - roi

#include <stdio.h>
#include <stdarg.h>

int
	ft_printf(char const *format, ...);

// #ifndef REAL // uncomment for ft_prntf check test - roi
# define REAL
#ifdef REAL
# define F	r += printf
# define A	r += ft_printf
#else
# define F	r += printf
#endif

int
	main(void)
{
	int	r;

	r = 0;
	F("Simple test\n");
	F("");
	F("--Format---");
	F("\n");
	F("%d\n", 0);
	F("%d\n", 42);
	F("%d\n", 1);
	F("%d\n", 5454);
	F("%d\n", (int)2147483647);
	F("%d\n", (int)2147483648);
	F("%d\n", (int)-2147483648);
	F("%d\n", (int)-2147483649);
	F("\n");
	F("%x\n", 0);
	F("%x\n", 42);
	F("%x\n", 1);
	F("%x\n", 5454);
	F("%x\n", (int)2147483647);
	F("%x\n", (int)2147483648);
	F("%x\n", (int)-2147483648);
	F("%x\n", (int)-2147483649);
	F("%x\n", (int)0xFFFFFFFF);
	F("\n");
	F("%s\n", "");
	F("%s\n", "toto");
	F("%s\n", "wiurwuyrhwrywuier");
	F("%s\n", NULL);
	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	F("\n--Mixed---\n");
	F("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	F("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	F("\n");
	F("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	F("%s\n", "toto");
	F("\n");
	F("Magic %s is %d", "number", 42);
	F("\n");
	F("Hexadecimal for %d is %x\n", 42, 42);
	F("\n");
	printf("written: %d\n", r);

	r = 0;
	A("Simple test\n");
	A("");
	A("--Format---");
	A("\n");
	A("%d\n", 0);
	A("%d\n", 42);
	A("%d\n", 1);
	A("%d\n", 5454);
	A("%d\n", (int)2147483647);
	A("%d\n", (int)2147483648);
	A("%d\n", (int)-2147483648);
	A("%d\n", (int)-2147483649);
	A("\n");
	A("%x\n", 0);
	A("%x\n", 42);
	A("%x\n", 1);
	A("%x\n", 5454);
	A("%x\n", (int)2147483647);
	A("%x\n", (int)2147483648);
	A("%x\n", (int)-2147483648);
	A("%x\n", (int)-2147483649);
	A("%x\n", (int)0xFFFFFFFF);
	A("\n");
	A("%s\n", "");
	A("%s\n", "toto");
	A("%s\n", "wiurwuyrhwrywuier");
	A("%s\n", NULL);
	A("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	A("\n--Mixed---\n");
	A("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	A("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	A("\n");
	A("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	A("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	A("%s\n", "toto");
	A("\n");
	A("Magic %s is %d", "number", 42);
	A("\n");
	A("Hexadecimal for %d is %x\n", 42, 42);
	A("\n");
	printf("written: %d\n", r);
}