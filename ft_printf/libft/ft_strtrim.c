/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:51:48 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/17 16:31:01 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_belong(char c, char const *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] != c)
		i ++;
	if (s[i] == c)
		return (1);
	else
		return (0);
}

static size_t	new_len(char const *s1, char const *set, \
size_t len, size_t end_trim)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	else if (len == 1)
		return (1 - ft_belong(s1[0], set));
	else
	{
		while (s1[i] && ft_belong(s1[i], set))
			i ++;
	}
	if (i == len)
		i = 0;
	return (len - i - end_trim);
}

static size_t	to_trim(char const *s1, char const *set, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	while (len && ft_belong(s1[len - 1], set))
	{
		len --;
		i ++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	end_trim;

	len = ft_strlen(s1);
	end_trim = to_trim(s1, set, len);
	s2 = malloc(new_len(s1, set, len, end_trim) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < len - end_trim && ft_belong(s1[i], set))
		i ++;
	while (s1[i] && i < len - end_trim)
	{
		s2[j] = s1[i];
		i ++;
		j ++;
	}
	s2[j] = '\0';
	return (s2);
}
