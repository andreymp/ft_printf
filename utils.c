/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:38:30 by jobject           #+#    #+#             */
/*   Updated: 2021/10/21 16:27:14 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_length(int n)
{
	int	size;

	size = 0;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	size++;
	if (n < 0)
		size++;
	return (size);
}

int	get_ulength(unsigned int n)
{
	int	size;

	size = 0;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	size++;
	if (n < 0)
		size++;
	return (size);
}

int	to_hex(unsigned	long long dig, char	*set)
{
	char	hex[100];
	int		i;
	int		j;

	ft_bzero(hex, 100);
	i = 0;
	while (dig / 16)
	{
		*(hex + i++) = *(set + (dig % 16));
		dig /= 16;
	}
	*(hex + i++) = *(set + (dig % 16));
	*(hex + i) = '\0';
	j = i - 1;
	while (j != -1)
	{
		ft_putchar_fd(*(hex + j), 1);
		j--;
	}
	ft_bzero(hex, 100);
	return (i);
}

void	ft_putunbr_fd(unsigned int num, int fd)
{
	unsigned int	length;
	unsigned int	i;
	char			res[11];

	ft_bzero(res, 11);
	length = get_ulength(num);
	i = length - 1;
	while (i && num / 10)
	{
		*(res + i) = num % 10 + 48;
		num /= 10;
		i--;
	}
	*(res + i) = num + 48;
	ft_putstr_fd(res, fd);
	ft_bzero(res, 11);
}
