/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:19:52 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 16:19:53 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_c(t_data *data)
{
	data->c = (char)data->intc;
	if (data->width > 1)
		case_1_c(data);
	else
		putchar_len(data->c, data);
}

int		case_1_c(t_data *data)
{
	if (data->width > 1 && data->minus)
	{
		putchar_len(data->c, data);
		putchar_ameliore((data->width - 1), ' ', data);
		return (0);
	}
	if ((data->width > 1 && data->zero))
		putchar_ameliore((data->width - 1), '0', data);
	else if (data->width > 1 && !data->minus)
		putchar_ameliore((data->width - 1), ' ', data);
	putchar_len(data->c, data);
	return (0);
}

int		case_4_d(int j, t_data *data)
{
	if (data->d < 0)
	{
		putchar_len('-', data);
		putchar_len('0', data);
		data->moins = '-';
	}
	putchar_ameliore(j, '0', data);
	putnbr(data->d, data);
	return (0);
}
