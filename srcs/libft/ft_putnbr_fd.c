/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:52:38 by atourret          #+#    #+#             */
/*   Updated: 2020/11/25 17:54:41 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	result;

	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	result = n;
	if (result >= 10)
		ft_putnbr_fd(result / 10, fd);
	ft_putchar_fd('0' + result % 10, fd);
}
