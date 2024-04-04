/* Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------
Write a function named `ft_printf` that will mimic the real printf but 
it will manage only the following conversions: s,d and x.
Your function must be declared as follows:
int ft_printf(const char *, ... );
Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.
Exemples of the function output:
call: ft_printf("%s\n", "toto");
out: toto$
call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%
call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$
Obs: Your function must not have memory leaks. Moulinette will test that. */

#include <stdarg.h>
#include <unistd.h>
#define HEX "0123456789abcdef"

int ft_dx_out(unsigned int number, int base, int flag)
{
    static int i = 0;

    if (flag)
        i = 0;
    if (number / base)
        ft_dx_out(number / base, base, 0);
    i += write(1, &HEX[number % base], 1);
    return (i);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    int i = 0;
    char *s = NULL;
    int d = 0;

    va_start(ap, str);
    while (*str)
    {
        if (*str == '%' && (*(str + 1) == '%' ||  *(str + 1) == 's' || 
            *(str + 1) == 'x' || *(str + 1) == 'd'))
        {
            str++;
            if (*str == '%')
                i += write(1, str, 1);
            else if (*str == 's')
            {
                s = va_arg(ap, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                    i += write(1, s++, 1);
            }
            else if (*str == 'x')
                i += ft_dx_out(va_arg(ap, unsigned int), 16, 1);
            else if (*str == 'd')
            {
                d = va_arg(ap, int);
                if (d == -2147483648)
                    i += write(1, "-2147483648", 11);
                else 
                {
                    if (d < 0)
                    {
                        i += write(1, "-", 1);
                        d = -d;
                    }
                    i += ft_dx_out(d, 10, 1);
                }
            }
        }
        else
            i += write(1, str, 1);
        str++;
    }
    va_end(ap);
    return (i);
}

// #include <stdio.h>  // printf
// #include <limits.h>  // INT_MIN, INT_MAX
// #define P k += printf
// #define A k += ft_printf

// int ft_printf(const char *str, ...);

// int main(void)
// {
// 	int k = 0;
	
// 	P("");
// 	P("\n");
// 	P("abcd4321\\\n");
// 	P("abcd4321\\%%%%\n");
// 	P("%s\n", "jjlmn");
// 	P("%s\n", "");
// 	P("%s\n", NULL);
// 	P("\n");
// 	P("%d\n", 0);
// 	P("%d\n", INT_MIN);
// 	P("%d\n", INT_MAX);
// 	P("\n");
// 	P("%x\n", 0);
// 	P("%x\n", 999);
// 	P("%x\n", INT_MAX);
// 	printf("Total printed out %d characters\n", k);
	
// 	k = 0;

// 	A("");
// 	A("\n");
// 	A("abcd4321\\\n");
// 	A("abcd4321\\%%%%\n");
// 	A("%s\n", "jjlmn");
// 	A("%s\n", "");
// 	A("%s\n", NULL);
// 	A("\n");
// 	A("%d\n", 0);
// 	A("%d\n", INT_MIN);
// 	A("%d\n", INT_MAX);
// 	A("\n");
// 	A("%x\n", 0);
// 	A("%x\n", 999);
// 	A("%x\n", INT_MAX);
// 	printf("Total printed out %d characters\n", k);
// }
