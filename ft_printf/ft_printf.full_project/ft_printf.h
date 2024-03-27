/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:17:03 by oruban            #+#    #+#             */
/*   Updated: 2024/03/27 09:15:42 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
# define HEX    "0123456789abcdef"
# define HEXCAP "0123456789ABCDEF"

int				ft_printf(const char *s, ...);
int				uns_out(unsigned int u, int i);
unsigned int	hex_out(char x, va_list ap);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
#endif
