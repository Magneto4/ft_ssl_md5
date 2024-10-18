/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:34:38 by nseniak           #+#    #+#             */
/*   Updated: 2022/05/19 18:32:10 by nseniak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] == c && str[j])
			j ++;
		while (!(str[j] == c) && str[j])
			j ++;
		if (!(str[j - 1] == c))
			i ++;
	}
	return (i);
}

static int	word_length(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] == c))
		i ++;
	return (i);
}

static char	**mallocs(char **tab, char *str, char c)
{
	int		i;

	i = 0;
	while (str != NULL && *str)
	{
		while (*str == c)
			str ++;
		if (!(*str))
			break ;
		tab[i] = malloc((word_length(str, c) + 1) * sizeof (**tab));
		if (!tab[i])
		{
			while (tab++)
				free(*tab);
			return (NULL);
		}
		while (*str && *str != c)
			str ++;
		i ++;
	}
	tab[i] = 0;
	return (tab);
}

static void	fill(char *str, char c, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (str != NULL && *str)
	{
		while (*str == c)
			str ++;
		if (!(*str))
			break ;
		j = 0;
		while (*str != c && *str)
		{
			tab[i][j] = *str;
			str ++;
			j ++;
		}
		tab[i][j] = '\0';
		i ++;
	}
	tab[i] = 0;
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	tab = malloc((word_count((char *)str, c) + 1) * sizeof(*tab));
	if (!tab)
		return (NULL);
	mallocs(tab, (char *)str, c);
	if (!tab)
		return (NULL);
	fill((char *)str, c, tab);
	return (tab);
}
