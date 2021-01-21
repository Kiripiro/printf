/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:08:54 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 15:59:29 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int		nb_d(long int nb, t_data *data)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		if (data->type != 'u')
			i = i + 1;
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int		nbx(unsigned long i)
{
	int j;

	j = 0;
	while ((i = i / 16) > 0)
		j++;
	return (j);
}

void	putnbr(long int nb, t_data *data)
{
	if (nb < 0)
	{
		if (data->type != 'u' && data->moins == 'x')
			putchar_len('-', data);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		putnbr(nb / 10, data);
		putnbr(nb % 10, data);
	}
	else
		putchar_len(nb + '0', data);
}

void	putnbr_unsigned(unsigned int nb, t_data *data)
{
	if (nb == 0 && data->precision == 0 && data->dot)
	{
		if (data->width > 0)
			putchar_len(' ', data);
		return ;
	}
	if (nb >= 10)
	{
		putnbr(nb / 10, data);
		putnbr(nb % 10, data);
	}
	else
		putchar_len(nb + '0', data);
}

void	putchar_ameliore(int end, char c, t_data *data)
{
	int i;

	i = 0;
	if (end < 0)
		return ;
	while (i < end)
	{
		data->len++;
		write(1, &c, 1);
		i++;
	}
}
