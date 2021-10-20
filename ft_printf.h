/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:56:19 by jobject           #+#    #+#             */
/*   Updated: 2021/10/20 20:09:07 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char	*s, ...);
int		ft_decimal(va_list ap);
int		get_length(int n);
int		ft_char(va_list ap);
int		ft_string(va_list	ap);
int		ft_pointer(va_list	ap);
int		ft_ud(va_list	ap);
int		ft_hex_upper(va_list	ap);
int		ft_hex_lower(va_list	ap);
int		ft_percent(void);
int		to_hex(unsigned long long dig, char	*set);
void	ft_putunbr_fd(unsigned int num, int fd);
int		get_ulength(unsigned int n);

#endif
