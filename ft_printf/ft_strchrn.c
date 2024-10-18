/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magneto <magneto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:16:03 by magneto           #+#    #+#             */
/*   Updated: 2022/05/24 15:33:22 by magneto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchrn(const char *s, int c, int n)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c && i < n)
		i ++;
	if (s[i] == (unsigned char)c)
		return (1);
	else
		return (0);
}
