#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int ft_printf(const char *format, ...);
int	put_char(char c);
int	put_str(char *str);
int numlen(unsigned int nbr);
int	put_nbr(int nbr);
int	put_unbr(unsigned int nbr);
int	put_hex(int n, char c_case);
int	put_ptr(unsigned long n);

#endif
