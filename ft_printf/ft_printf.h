/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 02:31:50 by chanjeon          #+#    #+#             */
/*   Updated: 2022/04/15 04:50:30 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *s);
char	*ft_putnbr_base(unsigned long long int num, char *str_base);
int		ft_print_str(char *s);
int		ft_printf(const char *format, ...);
void	set_conv(va_list *ap, const char **c, int *len);
int		print_p(va_list *ap);
int		print_c(va_list *ap);
int		print_s(va_list *ap);
int		print_diux(va_list *ap, const char *c);
int		print_id(va_list *ap);
int		print_u(va_list *ap);
int		print_x(va_list *ap, const char *c);
int		parse_format(va_list *ap, const char *format);

#endif
