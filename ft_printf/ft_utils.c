/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:12:28 by chanjeon          #+#    #+#             */
/*   Updated: 2022/04/16 08:25:29 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_base(unsigned long long num, char *str_base)
{
	int					base;
	int					cnt;
	unsigned long long	nb;
	char				*result;

	base = ft_strlen(str_base);
	nb = num;
	cnt = 1;
	nb /= base;
	while (nb > 0)
	{
		nb /= base;
		cnt++;
	}
	result = (char *)malloc(sizeof(char) * cnt + 1);
	if (!result)
		return (0);
	result[cnt] = '\0';
	while (cnt > 0)
	{
		result[cnt - 1] = str_base[num % base];
		cnt--;
		num /= base;
	}
	return (result);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
