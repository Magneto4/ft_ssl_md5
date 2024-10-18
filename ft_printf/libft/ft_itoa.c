/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:04:05 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/09 16:00:42 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_lenght(int n)
{
	int	i;

	if (n <= 0)
		i = 1;
	else
		i = 0;
	while (n)
	{
		n = n / 10;
		i ++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			i;
	long int	n2;

	n2 = (long int)n;
	i = int_lenght(n);
	nbr = malloc(i + 1);
	if (!nbr)
		return (NULL);
	if (n2 < 0)
	{
		n2 *= (-1);
		nbr[0] = '-';
	}
	if (n2 == 0)
		nbr[0] = '0';
	nbr[i] = '\0';
	while (n2)
	{
		i--;
		nbr[i] = '0' + n2 % 10;
		n2 = n2 / 10;
	}
	return (nbr);
}
