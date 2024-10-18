/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:24:06 by magneto           #+#    #+#             */
/*   Updated: 2022/05/24 15:48:48 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i ++;
	}
	return (i);
}

int	nbr_len_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i ++;
	}
	return (i);
}
