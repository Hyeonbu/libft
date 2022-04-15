/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:59:47 by chanjeon          #+#    #+#             */
/*   Updated: 2022/04/16 07:56:09 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	result = format_branch(&ap, (char *)format);
	va_end(ap);
	return (result);
}

int	format_branch(va_list *ap, const char *format)
{
	int	read_len;
	int	conv_len;

	read_len = 0;
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			read_len++;
			format++;
		}
		else
		{
			conv_len = 0;
			format++;
			set_conv(ap, &format, &conv_len);
			if (conv_len < 0)
				return (-1);
			read_len += conv_len;
		}
	}
	return (read_len);
}

void	set_conv(va_list *ap, const char **c, int *len)
{
	if (**c == 'c')
		*len = print_c(ap);
	if (**c == 's')
		*len = print_s(ap);
	if (**c == 'd' || **c == 'i' || **c == 'u' || **c == 'x' || **c == 'X')
		*len = print_idux(ap, *c);
	if (**c == '%')
	{
		write(1, "%", 1);
		*len += 1;
	}
	if (**c == 'p')
	{
		*len = print_p(ap);
	}
	(*c)++;
}
