/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:30:58 by magneto           #+#    #+#             */
/*   Updated: 2022/05/24 16:08:37 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	zero(char *str)
{
	int	zero;
	int	j;

	zero = 0;
	j = 0;
	while (!(ft_strchr(CONVERSIONS, str[j])))
	{
		if (str[j] == '0' && (!(str[j - 1]) || str[j - 1] != '.'))
			zero = 1;
		else if (ft_isdigit(str[j]))
		{
			while (ft_isdigit(str[j + 1]))
				j ++;
		}
		j ++;
	}
	return (zero);
}
