/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:15:52 by magneto           #+#    #+#             */
/*   Updated: 2022/05/23 13:02:52 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_to_print(int n, int precision)
{
	int	count;

	count = nbr_len_unsigned(n);
	if (precision > count)
		return (precision);
	return (count);
}

int	print_u_4(int min, int zero, int count, int left_justify)
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

void	print_u_3(unsigned int n, int precision)
{
	int	count;
	int	n_len;

	n_len = nbr_len_unsigned(n);
	count = 0;
	while (precision && count < precision - n_len)
	{
		ft_putchar_fd('0', 1);
		count ++;
	}
	ft_putnbr_unsigned(n);
}

int	print_u_2(char *str, unsigned int n, int min, int zero)
{
	int	i;
	int	count;
	int	precision;
	int	left_justify;

	precision = 0;
	i = 0;
	while (!(ft_strchr(CONVERSIONS, str[i])))
	{
		if (str[i] == '.')
		{
			precision = ft_atoi(str + i + 1);
			while (ft_isdigit(str[i + 1]))
				i ++;
		}
		i ++;
	}
	left_justify = ft_strchrn(str, '-', i);
	count = len_to_print(n, precision);
	if (left_justify)
		print_u_3(n, precision);
	count += print_u_4(min, zero, count, left_justify);
	if (!left_justify)
		print_u_3(n, precision);
	return (count);
}

int	print_u_1(char *str, int i, va_list args)
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
		else if ((ft_isdigit(str[j]) && str[j - 1] && str[j - 1] != '.'))
		{
			min = ft_atoi(str + j);
			while (ft_isdigit(str[j + 1]))
				j ++;
		}
		j ++;
	}
	return (print_u_2(str, va_arg(args, unsigned int), min, zero));
}
