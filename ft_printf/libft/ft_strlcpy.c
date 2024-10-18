/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:15:38 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/04 12:43:43 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 0 && i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i ++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
