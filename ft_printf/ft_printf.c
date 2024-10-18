/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:03:21 by magneto           #+#    #+#             */
/*   Updated: 2022/06/01 14:50:42 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_special(char *str, va_list args)
{
	int	i;

	i = 0;
	while (str[i] && !(ft_strchr(CONVERSIONS, str[i])))
		i ++;
	if (str[i] == 'c')
		return (print_c_1(str, i, args));
	if (str[i] == 's')
		return (print_s_1(str, i, args));
	if (str[i] == 'p')
		return (print_p_1(str, i, args));
	if (str[i] == 'd' || str[i] == 'i')
		return (print_d_i_1(str, i, args));
	if (str[i] == 'u')
		return (print_u_1(str, i, args));
	if (str[i] == 'x')
		return (print_x_1(str, i, args));
	if (str[i] == 'X')
		return (print_upperx_1(str, i, args));
	if (str[i] == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	print_normal(char *str)
{
	int	count;

	count = 0;
	while (*str && *str != '%')
	{
		ft_putchar_fd(*str, 1);
		count ++;
		str ++;
	}
	return (count);
}

int	parse_string(char *str, va_list args)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str ++;
			count += print_special(str, args);
			while (*str && !(ft_strchr(CONVERSIONS, *str)))
				str ++;
			str ++;
		}
		else
		{
			count += print_normal(str);
			while (*str && *str != '%')
				str ++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		output;

	va_start(args, str);
	output = parse_string((char *)str, args);
	va_end(args);
	return (output);
}
