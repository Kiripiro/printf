/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:07:45 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 16:02:29 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int		print_u(t_data *data)
{
	int nbd;
	int i;
	int j;

	if (data->u2 >= 0)
		nbd = nb_d(data->u2, data);
	else
		nbd = unsigned_nbd((unsigned)data->u2);
	i = data->width - nbd;
	j = data->precision - nbd;
	if (data->width < nbd || data->precision < nbd)
		case_1_u(nbd, i, j, data);
	else
		case_2_u(i, j, data);
	return (0);
}

int		case_1_u(int nbd, int i, int j, t_data *data)
{
	if (data->width > nbd && data->minus)
	{
		putnbr_unsigned(data->u2, data);
		putchar_ameliore(i, ' ', data);
		return (0);
	}
	if ((data->width > nbd && data->zero) && !data->dot)
		putchar_ameliore(i, '0', data);
	else if (data->width > nbd && !data->minus)
		putchar_ameliore(i, ' ', data);
	if (data->precision > nbd)
		putchar_ameliore(j, '0', data);
	putnbr_unsigned((unsigned)data->u2, data);
	return (0);
}

int		case_2_u(int i, int j, t_data *data)
{
	if (data->width > data->precision && data->minus)
	{
		putchar_ameliore(j, '0', data);
		putnbr_unsigned(data->u2, data);
		putchar_ameliore(i - j, ' ', data);
		return (0);
	}
	if (data->width > data->precision && !data->minus)
	{
		putchar_ameliore(i - j, ' ', data);
		putchar_ameliore(j, '0', data);
	}
	else
		putchar_ameliore(j, '0', data);
	putnbr_unsigned(data->u2, data);
	return (0);
}

int		unsigned_nbd(unsigned long int nb)
{
	int i;

	i = 1;
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}
