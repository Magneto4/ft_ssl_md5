/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:19:49 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/16 21:28:04 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	c = c % 256;
	result = NULL;
	while (s[i])
	{
		if (s[i] == c)
			result = (char *)s + i;
		i ++;
	}
	if (c == '\0')
		result = (char *)s + i;
	return (result);
}
