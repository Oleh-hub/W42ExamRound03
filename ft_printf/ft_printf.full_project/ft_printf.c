/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:36:22 by oruban            #+#    #+#             */
/*   Updated: 2024/03/27 09:21:42 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stdarg.h included just as a reminder. it is included in ft_printf.h as well
#include <stdarg.h>
#include "ft_printf.h"

// upxx_out.c === start

// prints out unsigned integer 
// PARAMETERS
// 'unsigned int u 'to print out and 'int reset_counter' that should always 
// be = 1 (it is = 0 only in recursion calls insiged the funciton)
// RETURN
// the number of outputed symbols or -1 if a write fails
// NB:
// it is not polite to create a variable that can be negative for a counter
// but i want to use it later in ft_itoa, besides
// the counter i is of int type because i is never > (UINT_MAX = 4294967295)
int	uns_out(unsigned int u, int reset_counter)
{
	char		c;
	static int	i = 0;

	if (reset_counter)
		i = 0;
	if (!u)
		return (write(1, "0", 1));
	if (u > 9)
		uns_out(u / 10, 0);
	c = u % 10 + '0';
	if (-1 == write(1, &c, 1))
		return (-1);
	return (++i);
}

// prints out a unsingned int number into hexedecimal format on eof '%xXp'
// PARAMETERS
// 'unsingned int u' - the number to be converted
// 'char x' can be 'x', 'X' or 'p' to output %x, %X or %p
// 'int reset_counter' = 1 for every call exeept recursion inside the function
// RETURN
// the nuber of outputed characters
unsigned int	xxc_out(unsigned int u, int reset_counter, char x)
{
	static int	i = 0;

	if (reset_counter)
		i = 0;
	if (!u)
		return (write(1, "0", 1));
	if (u > 15)
		xxc_out(u / 16, 0, x);
	if ('x' == x)
		if (-1 == write(1, &HEX[u % 16], 1))
			return (-1);
	if ('X' == x)
		if (-1 == write(1, &HEXCAP[u % 16], 1))
			return (-1);
	return (++i);
}

// prints out a unsingned long number into hexedecimal format of a 
// pointer address'%p'
// PARAMETERS
// 'unsingned long u' - the number to be converted
// 'char x' can be 'x', 'X' or 'p' to output %x, %X or %p
// 'int reset_counter' = 1 for every call exeept recursion inside the function
// RETURN
// the nuber of outputed characters
unsigned int	p_out(unsigned long u, int reset_counter, char x)
{
	static int	i = 0;

	if (reset_counter)
		i = 0;
	if (!u)
		return (write(1, "0", 1));
	if (u > 15)
		p_out(u / 16, 0, x);
	if (-1 == write(1, &HEX[u % 16], 1))
		return (-1);
	return (++i);
}

unsigned int	hex_out(char x, va_list ap)
{
	unsigned int	i;
	unsigned long	ul;
	unsigned int	ui;

	i = 0;
	if ('p' == x)
	{
		ul = va_arg(ap, unsigned long);
		i = write(1, "0x", 2);
		if (i < 0)
			return (i);
		i += p_out(ul, 1, x);
	}
	else
	{
		ui = va_arg(ap, unsigned int);
		if ('x' == x)
			i = xxc_out(ui, 1, x);
		else if ('X' == x)
			i = xxc_out(ui, 1, x);
	}
	return (i);
}
// upxx_out.c === end

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pntr;
	size_t			i;

	pntr = s;
	i = 0;
	c = (unsigned char) c;
	while (i < n)
	{
		pntr[i] = c;
		i++;
	}
	return (s);
}

//ft_memmove() ===start
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*s;
	unsigned char		*d;
	size_t				i;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	i = 0;
	if (dest < src && n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (dest > src && n)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}
//ft_memmove() ===end

// ft_itoa() ==start
static char	*i2a(int n, char *out)
{
	int	i;

	if (0 == n)
		out[0] = '0';
	else
	{
		i = ft_strlen(out);
		while (i > 0)
		{
			out[--i] = n % 10 + '0';
			n = n / 10;
		}
		if ('0' == out[0])
			out[0] = '-';
	}
	return (out);
}

static int	numlen(int n)
{
	if (n > 0)
		return (1 + numlen(n / 10));
	else
		return (0);
}
// 	// nsize = minus > 0 ? numlen(n) : numlen(n) + 1;
// out = malloc((nsize + 1) * sizeof(c

static int	find_size(int n)
{
	int		nsize;

	if (n < 0)
		nsize = numlen(-n) + 1;
	else
	{
		if (!n)
			nsize = 1;
		else
			nsize = numlen(n);
	}
	return (nsize);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		nsize;

	if (-2147483648 == n)
	{
		out = malloc(sizeof("-2147483648"));
		if (!out)
			return (NULL);
		out[ft_strlen("-2147483648")] = '\0';
		return (ft_memmove(out, "-2147483648", 11));
	}
	nsize = find_size (n);
	if (n < 0)
		n = -n;
	out = malloc((nsize + 1) * sizeof(char));
	if (!out)
		return (NULL);
	out = ft_memset(out, 'H', nsize);
	out[nsize] = '\0';
	out = i2a(n, out);
	return (out);
}
// ft_itoa() ==end

static int	int_out(int count, va_list ap)
{
	int		int_out;
	char	*str_out;

	int_out = va_arg(ap, int);
	str_out = ft_itoa(int_out);
	count += write(1, str_out, ft_strlen(str_out));
	free(str_out);
	return (count);
}

static int	str_out(int count, va_list ap)
{
	char	*str_out;

	str_out = NULL;
	str_out = va_arg(ap, char *);
	if (!str_out)
		return (count += write(1, "(null)", 6));
	count += write(1, str_out, ft_strlen(str_out));
	return (count);
}

static int	char_out(int count, va_list ap)
{
	char	char_out;

	char_out = (char) va_arg(ap, int);
	count += write(1, &char_out, 1);
	return (count);
}

static int	
cnvrtns_chc(const char**s, int count, va_list ap)
{
	unsigned int	uns;

	if ('%' == **s)
		count += write(1, *s, 1);
	else if ('c' == **s)
		count = char_out(count, ap);
	else if ('s' == **s)
		count = str_out(count, ap);
	else if ('d' == **s || 'i' == **s)
		count = int_out(count, ap);
	else if ('u' == **s)
	{
		uns = va_arg(ap, unsigned int);
		count += (unsigned int) uns_out(uns, 1);
	}
	else if ('x' == **s || 'X' == **s || 'p' == **s)
		count += (unsigned int) hex_out(**s, ap);
	(*s)++;
	return (count);
}

int	ft_printf(const char *s, ...)
{
	unsigned int	count;
	va_list			ap;

	count = 0;
	if (!*s || !s)
		return (0);
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && *++s)
			count = cnvrtns_chc(&s, count, ap);
		if (*s && *s != '%')
		{
			count += write(1, s, 1);
			s++;
		}
	}
	va_end(ap);
	return (count);
}
