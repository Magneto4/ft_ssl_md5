/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upperx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:26:41 by magneto           #+#    #+#             */
/*   Updated: 2022/05/24 15:48:43 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_to_print(char *str, int i, int n, int precision)
{
	int	count;

	count = 0;
	count += hexa_length((unsigned)n);
	if (ft_strchrn(str, '#', i) && n)
	{
		count += 2;
		precision += 2;
	}
	if (precision > count)
		return (precision);
	return (count);
}

int	print_upperx_4(int min, int zero, int count, int left_justify)
{
	int		i;
	char	to_print;

	if (zero && !left_justify)
		to_print = '0';
	else
		to_print = ' ';
	i = 0;
	while (count + i < min)
	{
		ft_putchar_fd(to_print, 1);
		i ++;
	}
	return (i);
}

void	print_upperx_3(int n, int precision, int x)
{
	int	count;
	int	n_len;

	n_len = hexa_length((unsigned int)n);
	count = 0;
	if (x && n)
		ft_putstr_fd("0X", 1);
	while (precision && count < precision - n_len)
	{
		ft_putchar_fd('0', 1);
		count ++;
	}
	print_hexa_upper((unsigned int)n);
}

int	print_upperx_2(char *str, int n, int min, int zero)
{
	int	i;
	int	count;
	int	precision;
	int	left_justify;

	precision = get_precision(str);
	i = 0;
	left_justify = ft_strchrn(str, '-', i);
	count = len_to_print(str, i, n, precision);
	if (zero && ft_strchrn(str, '#', i) && n)
		ft_putstr_fd("0X", 1);
	if (left_justify)
		print_upperx_3(n, precision, !zero && ft_strchrn(str, '#', i));
	count += print_upperx_4(min, zero, count, left_justify);
	if (!left_justify)
		print_upperx_3(n, precision, !zero && ft_strchrn(str, '#', i));
	return (count);
}

int	print_upperx_1(char *str, int i, va_list args)
{
	int	min;
	int	zero;
	int	j;

	min = 0;
	zero = 0;
	j = 0;
	while (j < i)
	{
		if (str[j] == '0')
			zero = 1;
		else if (ft_isdigit(str[j]) && str[j - 1])
		{
			if (str[j - 1] != '.')
				min = ft_atoi(str + j);
			while (ft_isdigit(str[j + 1]))
				j ++;
		}
		j ++;
	}
	return (print_upperx_2(str, va_arg(args, int), min, zero));
}
