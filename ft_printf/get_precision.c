/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:28:26 by magneto           #+#    #+#             */
/*   Updated: 2022/05/24 15:48:51 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_precision(char *str)
{
	int	i;
	int	precision;

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
	return (precision);
}
