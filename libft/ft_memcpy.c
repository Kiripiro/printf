/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:03:36 by atourret          #+#    #+#             */
/*   Updated: 2020/11/26 14:32:22 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (((char *)dst || (char *)src) && n > 0)
	{
		n--;
		((char *)dst)[n] = ((char *)src)[n];
	}
	return (dst);
}
