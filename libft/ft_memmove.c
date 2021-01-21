/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:43:06 by atourret          #+#    #+#             */
/*   Updated: 2020/11/26 16:04:05 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*cpydst;
	const char	*cpysrc;

	cpysrc = src;
	cpydst = dst;
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			cpydst[i] = cpysrc[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len--)
			cpydst[len] = cpysrc[len];
	}
	return (dst);
}
