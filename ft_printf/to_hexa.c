/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:26:24 by magneto           #+#    #+#             */
/*   Updated: 2022/05/24 15:48:42 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_upper(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr < 16)
	{
		ft_putchar_fd("0123456789ABCDEF"[nbr], 1);
		return (1);
	}
	else
	{
		i = 1 + print_hexa_upper(nbr / 16);
		ft_putchar_fd("0123456789ABCDEF"[nbr % 16], 1);
		return (i);
	}
}

int	print_hexa_lower(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr < 16)
	{
		ft_putchar_fd("0123456789abcdef"[nbr], 1);
		return (1);
	}
	else
	{
		i = 1 + print_hexa_lower(nbr / 16);
		ft_putchar_fd("0123456789abcdef"[nbr % 16], 1);
		return (i);
	}
}

int	print_hexa_lower_long(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		ft_putchar_fd("0123456789abcdef"[n], 1);
		return (1);
	}
	else
	{
		i = 1 + print_hexa_lower_long(n / 16);
		ft_putchar_fd("0123456789abcdef"[n % 16], 1);
		return (i);
	}
}

int	hexa_length(long int n)
{
	int					i;
	unsigned long long	nbr;

	nbr = (unsigned long long)n;
	i = 0;
	if (n == 0)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		i ++;
	}
	return (i);
}
