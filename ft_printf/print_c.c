/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:00:08 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/24 15:48:47 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c_1(char *str, int i, va_list args)
{
	int		left_justify;
	int		min;
	int		j;

	left_justify = 0;
	min = 0;
	j = 0;
	while (j < i)
	{
		if (str[j] == '-')
			left_justify = 1;
		else if (str[j] == '.')
		{
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
	return (print_c_2(va_arg(args, int), min, left_justify));
}

int	print_c_2(int c, int min, int left_justify)
{
	int	i;

	i = 0;
	if (left_justify)
		ft_putchar_fd(c, 1);
	while (min && i < min - 1)
	{
		ft_putchar_fd(' ', 1);
		i ++;
	}
	if (!left_justify)
		ft_putchar_fd(c, 1);
	if (min)
		return (min);
	return (1);
}
