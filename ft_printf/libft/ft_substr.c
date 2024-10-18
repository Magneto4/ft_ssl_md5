/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:27:19 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/04 12:22:39 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s)
		str = malloc(1);
	else if (len > len_s - start)
		str = malloc(len_s - start + 1);
	else
		str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (start < len_s)
	{
		while (i < (int)len && s[start + i])
		{
			str[i] = s[start + i];
			i ++;
		}
	}
	str[i] = '\0';
	return (str);
}
