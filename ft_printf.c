/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:56:26 by jobject           #+#    #+#             */
/*   Updated: 2021/10/18 19:56:28 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*new_str(const char	*s, int	num, char	c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc(num + 1);
	if (!str)
		return (NULL);
	while (*s != '%')
		*(str + i++) = *s++;
	while (*s != c)
		s++;
	*(str + i++) = c;
	s += 2;
	while (*s)
		*(str + i++)  = *s++;
	*(str + i) = '\0';
	return (str);
}

char	*choose_option(const char	*s)//, va_list	ap)
{
	int i;

	i = 0;
	while (*(s + i) != '%')
		i++;
	if (*(s + i + 1) == '%')
		return (new_str(s, ft_strlen(s) - 1, '%'));
	return (NULL);
}

int	ft_printf(const char	*s, ...)
{
	va_list	ap;
	char	*res;
	int		i;
	int		ret_value;

	va_start(ap, s);
	i = 0;
	while (*(s + i) && *(s + i) != '%')
		i++;
	res = NULL;
	if (*(s + i) == '%')
		res = choose_option(s);//, ap);
	va_end(ap);
	if (res)
	{
		ft_putstr_fd(res, 1);
		ret_value = ft_strlen(res);
		free (res);
	}
	else
		ft_putstr_fd((char *) s, 1);
	ret_value = -1;
	return (ret_value);
}

#include <stdio.h>
int main()
{
	printf("50 of smack my ass here");
	puts("");
	ft_printf("50 of smack my ass here");
}