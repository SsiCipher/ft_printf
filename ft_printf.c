/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:35:35 by yanab             #+#    #+#             */
/*   Updated: 2021/11/26 19:35:35 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		char_count;
	va_list	arg_ptr;

	i = 0;
	char_count = 0;
	va_start(arg_ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			char_count += put_char(format[i]);
			i++;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				char_count += put_char('%');
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				char	c = (char)va_arg(arg_ptr, int);
				char_count += put_char(c);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char	*s = (char *)va_arg(arg_ptr, char *);
				char_count += put_str(s);
				i++;
			}
			else if (format[i + 1] == 'p')
			{
				void	*ptr = (void *)va_arg(arg_ptr, void *);
				char_count += put_ptr((unsigned long)ptr);
				i++;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				int	n = (int)va_arg(arg_ptr, int);
				put_nbr(n);
				char_count += numlen(n);
				i++;
			}
			else if (format[i + 1] == 'u')
			{
				unsigned int	n = va_arg(arg_ptr, unsigned int);
				put_unbr(n);
				char_count += numlen(n);
				i++;
			}
			else if (format[i + 1] == 'x' || format[i + 1] == 'X')
			{
				int	n = (int)va_arg(arg_ptr, int);
				char_count += put_hex(n, format[i + 1]);
				i++;
			}
			i++;
		}
	}
	va_end(arg_ptr);
	return (char_count);
}
