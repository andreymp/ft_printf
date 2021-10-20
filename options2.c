/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:43:40 by jobject           #+#    #+#             */
/*   Updated: 2021/10/20 20:09:52 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_upper(va_list	ap)
{
	unsigned int	dig;

	dig = va_arg(ap, unsigned int);
	return (to_hex(dig, "0123456789ABCDEF") - 1);
}

int	ft_pointer(va_list	ap)
{
	unsigned long long	dig;

	ft_putstr_fd("0x", 1);
	dig = va_arg(ap, unsigned long long);
	return (to_hex(dig, "0123456789abcdef") + 1);
}

int	ft_ud(va_list	ap)
{
	unsigned int	dig;

	dig = va_arg(ap, unsigned int);
	ft_putunbr_fd(dig, 1);
	return (get_ulength(dig) - 1);
}
