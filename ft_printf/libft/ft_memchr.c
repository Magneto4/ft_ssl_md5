/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:31:49 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/16 20:40:59 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n > 1 && (*ptr != (unsigned char)c))
	{
		n --;
		ptr ++;
	}
	if (*ptr == (unsigned char)c)
		return (ptr);
	else
		return (NULL);
}
