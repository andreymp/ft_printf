/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:38:30 by jobject           #+#    #+#             */
/*   Updated: 2021/10/19 19:44:57 by jobject          ###   ########.fr       */
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

int	to_hex(unsigned long long	dig, char	*set)
{
	char	hex[100];
	int		i;
	int		j;

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
	return (i);
}
