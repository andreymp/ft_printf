/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:56:26 by jobject           #+#    #+#             */
/*   Updated: 2021/10/19 19:46:10 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_option(const char	*s, va_list	ap, int index)
{
	if (*(s + index + 1) == 'd' || *(s + index + 1) == 'i')
		return (ft_decimal(ap));
	if (*(s + index + 1) == 'c')
		return (ft_char(ap));
	if (*(s + index + 1) == 's')
		return (ft_string(ap));
	if (*(s + index + 1) == 'p')
		return (ft_pointer(ap));
	if (*(s + index + 1) == 'u')
		return (ft_ud(ap));
	if (*(s + index + 1) == 'x')
		return (ft_hex_lower(ap));
	if (*(s + index + 1) == 'X')
		return (ft_hex_upper(ap));
	if (*(s + index + 1) == '%')
		return (ft_percent());
	return (-1);
}

int	pars_string(const char	*s, va_list	ap)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (*(s + i))
	{
		if (*(s + i) == '%' && *(s + i + 1))
		{
			len += choose_option(s, ap, i);
			i++;
		}
		else
			ft_putchar_fd(*(s + i), 1);	
		i++;
		len++;
	}
	return (len);
}

int	ft_printf(const char	*s, ...)
{
	va_list	ap;
	int		ret_value;

	ret_value = 0;
	va_start(ap, s);
	ret_value = pars_string(s, ap);
	va_end(ap);
	return (ret_value);
}

#include <stdio.h>
int main()
{
	int a = -510;
	printf("%d", printf("%u\n", a));
	puts("");
	printf("%d", ft_printf("%u\n", a));
}

/*
обработать отрицательный u
пересмотреть p (NULL рабочий)
*/