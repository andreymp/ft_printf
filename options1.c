/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:42:47 by jobject           #+#    #+#             */
/*   Updated: 2021/10/19 19:16:56 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal(va_list ap)
{
	int decimal;

	decimal = va_arg(ap, int);
	ft_putnbr_fd(decimal, 1);
	return (get_length(decimal) - 1);
}

int ft_char(va_list ap)
{
	char	code;

	code = va_arg(ap, int);
	ft_putchar_fd(code, 1);
	return (0);
}

int	ft_string(va_list	ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str) - 1);
}

int	ft_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_hex_lower(va_list	ap)
{
	unsigned int	dig;

	dig = va_arg(ap, unsigned int);
	return (to_hex(dig, "0123456789abcdef") - 1);
}
