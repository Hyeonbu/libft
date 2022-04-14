/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:47:21 by chanjeon          #+#    #+#             */
/*   Updated: 2022/04/15 04:28:38 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list *ap)
{
	int		cnt;
	char	result;

	cnt = 0;
	result = va_arg((*ap), int);
	write(1, &result, 1);
	cnt++;
	return (cnt);
}

int	print_s(va_list *ap)
{
	int		cnt;
	char	*result;

	cnt = 0;
	result = va_arg((*ap), char *);
	if (result == NULL)
	{
		write(1, "(null)", 6);
		cnt += 6;
		return (cnt);
	}
	while (*result != '\0')
	{
		write(1, result, 1);
		result++;
		cnt++;
	}
	return (cnt);
}

int	print_p(va_list *ap)
{
	int			cnt;
	char		*result;
	uintptr_t	tmp;

	tmp = va_arg((*ap), uintptr_t);
	write(1, "0x", 2);
	cnt = 2;
	result = ft_putnbr_base(tmp, "0123456789abcdef");
	cnt += ft_print_str(result);
	free(result);
	return (cnt);
}
