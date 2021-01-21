/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:55:39 by atourret          #+#    #+#             */
/*   Updated: 2020/11/27 11:19:52 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*obj;
	int		i;

	i = 0;
	if (!(obj = (char *)malloc(sizeof(char) * (count * size))))
		return (0);
	ft_bzero(obj, count * size);
	return (obj);
}
