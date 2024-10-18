/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:24:11 by magneto           #+#    #+#             */
/*   Updated: 2022/05/24 15:48:46 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p_1(char *str, int i, va_list args)
{
	int	min;
	int	j;

	min = 0;
	j = 0;
	while (j < i)
	{
		if (ft_isdigit(str[j]))
		{
			min = ft_atoi(str + j);
			while (ft_isdigit(str[j + 1]))
				j ++;
		}
		j ++;
	}
	return (print_p_2(va_arg(args, void *), min, ft_strchrn(str, '-', i)));
}

int	ptr_null(void)
{
	ft_putstr_fd("(nil)", 1);
	return (5);
}

int	print_p_2(void *ptr, int min, int left_justify)
{
	int	count;

	if (!ptr)
		return (ptr_null());
	count = hexa_length((long int)ptr) + 2;
	if (left_justify)
	{
		ft_putstr_fd("0x", 1);
		print_hexa_lower_long((long int)ptr);
	}
	while (count < min)
	{
		count ++;
		ft_putchar_fd(' ', 1);
	}
	if (!left_justify)
	{
		ft_putstr_fd("0x", 1);
		print_hexa_lower_long((long unsigned int)ptr);
	}
	return (count);
}
