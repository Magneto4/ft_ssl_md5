/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:15:52 by magneto           #+#    #+#             */
/*   Updated: 2022/05/24 16:08:50 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_to_print(char *str, int i, int n, int precision)
{
	int	count;

	count = 0;
	if (ft_strchrn(str, ' ', i) || ft_strchrn(str, '+', i) || n < 0)
	{
		precision ++;
		count ++;
	}
	if (n < 0)
		count += nbr_len((unsigned int)(-1 * (long int)n));
	else
		count += nbr_len((unsigned int)n);
	if (precision > count)
		return (precision);
	return (count);
}

int	print_d_i_4(int min, int zero, int count, int left_justify)
{
	int		i;
	char	to_print;

	if (zero && !left_justify)
		to_print = '0';
	else
		to_print = ' ';
	i = 0;
	while (min && count + i < min)
	{
		ft_putchar_fd(to_print, 1);
		i ++;
	}
	return (i);
}

void	print_d_i_3(int n, char *str, int i, int precision)
{
	int	count;
	int	n_len;

	n_len = nbr_len(n);
	count = 1;
	if (n >= 0)
	{
		if (ft_strchrn(str, '+', i))
			ft_putchar_fd('+', 1);
		else if (ft_strchrn(str, ' ', i))
			ft_putchar_fd(' ', 1);
		count --;
	}
	else if (!(zero(str)))
	{
		ft_putchar_fd('-', 1);
		count --;
	}
	while (precision && count < precision - n_len)
	{
		ft_putchar_fd('0', 1);
		count ++;
	}
	ft_putnbr_absolute(n);
}

int	print_d_i_2(char *str, int n, int min, int zero)
{
	int	count;
	int	precision;
	int	left_justify;
	int	i;

	i = 0;
	while (!(ft_strchr(CONVERSIONS, str[i])))
		i++;
	precision = get_precision(str);
	left_justify = ft_strchrn(str, '-', i);
	count = len_to_print(str, i, n, precision);
	if (zero && (n < 0))
		ft_putchar_fd('-', 1);
	if (left_justify)
		print_d_i_3(n, str, i, precision);
	count += print_d_i_4(min, zero, count, left_justify);
	if (!left_justify)
		print_d_i_3(n, str, i, precision);
	return (count);
}

int	print_d_i_1(char *str, int i, va_list args)
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
		else if (ft_isdigit(str[j]))
		{
			if (str[j - 1] != '.')
				min = ft_atoi(str + j);
			while (ft_isdigit(str[j + 1]))
				j ++;
		}
		j ++;
	}
	return (print_d_i_2(str, va_arg(args, int), min, zero));
}
