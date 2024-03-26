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

#include <stdio.h>
#include <string.h>
#include <unistd.h> // write
#include <stdarg.h> // va_start, va_end, va_arg
#include <stdlib.h> // malloc, free


static int ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

static int ft_ilen(int number)
{
	int i = 0;

	if (number < 0)
	{
		i++;
		number = -number;
	}
	while (number >= 1)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int i)
{
	char *a = "-2147483648"; //INT_MIN
	int len = 0;

	if (i == -2147483648)
		return (a);
	a = NULL;
	len = ft_ilen(i);
	a = (char *) malloc(len + 1);
	a[len] = '\0';
	if (i < 0)
	{
		a[0] = '-';
		i = -i;
	}
	while (i)
	{
		len--;
		a[len] = i % 10 + '0';
		i = i / 10;
	}
	return (a);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	int d;
	char *s;
	unsigned int count = 0;

	if(!str)
		return (0);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			switch(*str)
			{
				case '%':                       /* % */
					count += write(1, str, 1);
					break;
				case 's':                       /* string */
					s = va_arg(ap, char *);
					write(1, s, ft_strlen(s));
					break;
				case 'd':                       /* int */
					d = va_arg(ap, int);
					s = ft_itoa(d);
					write(1, s, ft_strlen(s));
					if (d != -2147483648)
						free (s);
					break;
				case 'x':                       /* hexidecimal */
				// 	/* Note: char is promoted to int. */
				// 	c = va_arg(ap, int);
				// 	printf("char %c\n", c);
				// 	break;
				default:
				;
			}
			str++;
		}
		else
		{
			count += write(1, str, 1);
			str++;
		}		
	}
	va_end(ap);
	return(count);
}
