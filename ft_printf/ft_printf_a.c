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

#include <stdarg.h> // va_start, va_end, va_arg
#include <unistd.h> //write
#include <stdlib.h> //malloc, free
#define HEX "0123456789abcdef"

int ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

int ilen(int d)
{
	int i = 0;

	if (d == 0)
		return (1);
	if (d < 0)
	{
		i++;
		d = -d;
	}
	while (d)
	{
		d = d /10;
		i++;
	}
	return (i);
}

char *itoa(int d)
{
	char *s = "-2147483648";
	int len = 0;
	
	if (d == -2147483648)
		return (s);
	s = NULL;
	len = ilen(d);
	s = (char *) malloc(len * sizeof(char) + 1);
	s[len] = '\0';
	if (d == 0)
		s[0] = '0';
	if (d < 0)
	{
		s[0] = '-';
		d = -d;
	}
	while (d)
	{
		len--;
		s[len] = d % 10 + '0';
		d = d / 10;
	}
	return (s);
}

int write_ui_as_x(unsigned int ui, int flag)
{
	static int i = 0;

	if (flag)
		i = 0;
	if (!ui)
		return (i);
	write_ui_as_x(ui / 16, 0);
	i += write(1, &HEX[ui % 16], 1);
	return (i);
}

int ft_printf(const char *str, ... )
{
	va_list ap;
	int i = 0;
	int d = 0;
	char *s = NULL;
	unsigned int ui = 0;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(++str))
		{
			if (*str == '%')
				i += write(1, str, 1);
			else if (*str == 's')
			{
				s = va_arg(ap, char *);
				if (!s)
					i += write(1, "(null)", 6);
				else
					i += write(1, s, ft_strlen(s));
			}
			else if (*str == 'd')
			{
				d = va_arg(ap, int);
				s = itoa(d);
				i += write(1, s, ft_strlen(s));
				if ( d != -2147483648)
					free(s);
			}
			else if (*str == 'x')
			{
				ui = va_arg(ap, unsigned int);
				if (!ui)
					i += write(1, "0", 1);
				else
				i += write_ui_as_x(ui, 1);
			}
		}
		else
			i += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (i);
}
