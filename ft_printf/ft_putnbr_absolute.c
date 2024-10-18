/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_absolute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:51:19 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/24 15:48:52 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_absolute(long int nb)
{
	int	q;
	int	r;

	if (nb >= 0)
	{
		q = nb / 10;
		r = nb % 10 + '0';
	}
	else if (nb == -2147483648)
	{
		q = 214748364;
		r = 8 + '0';
	}
	else
	{
		q = (0 - nb) / 10;
		r = (0 - nb) % 10 + 48;
	}
	if (q != 0)
	{
		ft_putnbr_fd(q, 1);
	}
	write(1, &r, 1);
}

void	ft_putnbr_unsigned(long unsigned int nb)
{
	int	q;
	int	r;

	q = nb / 10;
	r = nb % 10 + '0';
	if (q != 0)
	{
		ft_putnbr_fd(q, 1);
	}
	write(1, &r, 1);
}
