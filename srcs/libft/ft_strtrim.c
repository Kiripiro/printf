/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:49:23 by atourret          #+#    #+#             */
/*   Updated: 2020/11/26 17:12:38 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	if (!s1)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (is_in_set(s1[i], set))
		i++;
	while (len > 0 && is_in_set(s1[len - 1], set))
		len--;
	if (len == 0)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (len - i) + 1)))
		return (0);
	while (s1[i] && i < len)
	{
		res[j++] = s1[i];
		i++;
	}
	res[j] = 0;
	return (res);
}
