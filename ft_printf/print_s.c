/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:04:24 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/24 15:48:45 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s_1(char *str, int i, va_list args)
{
	int	min;
	int	precision;
	int	j;

	min = 0;
	precision = 0;
	j = 0;
	while (j < i)
	{
		if (str[j] == '.')
		{
			precision = ft_atoi(str + j + 1);
			while (ft_isdigit(str[j + 1]))
				j ++;
		}
		else if (ft_isdigit(str[j]))
		{
			min = ft_atoi(str + j);
			while (ft_isdigit(str[j + 1]))
				j ++;
		}
		j ++;
	}
	return (print_s_2(va_arg(args, char *), min, precision, str));
}

int	null_arg(void)
{
	ft_putstr_fd("(null)", 1);
	return (6);
}

int	print_s_2(char *s, int min, int precision, char *str)
{
	int	len;
	int	i;
	int	left_justify;
	int	n;

	if (!s)
		return (null_arg());
	n = 0;
	while (!(ft_strchr(CONVERSIONS, str[n++])))
		n ++;
	left_justify = ft_strchrn(str, '-', n);
	len = ft_strlen(s);
	if ((ft_strchrn(str, '.', n)) && (precision < len))
		len = precision;
	if (left_justify)
		write(1, s, len);
	i = 0;
	while (i++ < min - len)
		ft_putchar_fd(' ', 1);
	if (!left_justify)
		write(1, s, len);
	if (min < len)
		return (len);
	return (min);
}
