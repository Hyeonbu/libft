/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 03:04:27 by chanjeon          #+#    #+#             */
/*   Updated: 2022/04/16 07:48:43 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_idux(va_list *ap, const char *c)
{
	int	cnt;

	cnt = 0;
	if (*c == 'i' || *c == 'd')
		cnt += print_id(ap);
	else if (*c == 'x' || *c == 'X')
		cnt += print_x(ap, c);
	else if (*c == 'u')
		cnt += print_u(ap);
	return (cnt);
}

int	print_id(va_list *ap)
{
	int			cnt;
	char		*result;
	long long	tmp;

	cnt = 0;
	tmp = va_arg((*ap), int);
	if (tmp == -2147483648)
	{
		write(1, "-2147483648", 11);
		cnt = 11;
		return (cnt);
	}
	else if (tmp > -2147483648 && tmp < 0)
	{
		tmp *= -1;
		write(1, "-", 1);
		cnt++;
	}
	result = ft_putnbr_base(tmp, "0123456789");
	cnt += ft_print_str(result);
	free(result);
	return (cnt);
}

int	print_u(va_list *ap)
{
	int			cnt;
	char		*result;
	long long	tmp;

	cnt = 0;
	tmp = va_arg((*ap), unsigned int);
	result = ft_putnbr_base(tmp, "0123456789");
	cnt += ft_print_str(result);
	free(result);
	return (cnt);
}

int	print_x(va_list *ap, const char *c)
{
	int			cnt;
	char		*result;
	long long	tmp;

	cnt = 0;
	result = 0;
	tmp = va_arg((*ap), unsigned int);
	if (tmp < 0)
	{
		tmp *= -1;
		write(1, "-", 1);
		cnt++;
	}
	if (*c == 'x')
		result = ft_putnbr_base(tmp, "0123456789abcdef");
	else if (*c == 'X')
		result = ft_putnbr_base(tmp, "0123456789ABCDEF");
	cnt += ft_print_str(result);
	free(result);
	return (cnt);
}
