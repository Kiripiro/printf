/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:04:15 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 15:59:24 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_d(t_data *data)
{
	long int	nbd;
	int			i;
	int			j;

	nbd = nb_d(data->d, data);
	i = data->width - nbd;
	j = data->precision - nbd;
	data->moins = 'x';
	if (data->width <= nbd || data->precision < nbd)
		case_1_d(nbd, i, j, data);
	else
	{
		if (data->width > data->precision && data->minus)
			case_2_d(i, j, data);
		else if (data->width > data->precision && !data->minus)
			case_3_d(i, j, data);
		else
			case_4_d(j, data);
	}
}

int		case_1_d(long int nbd, int i, int j, t_data *data)
{
	if (data->width > nbd && data->minus)
	{
		if (data->precision == 0 && data->d == 0 && data->dot)
			putchar_len(' ', data);
		else
			putnbr(data->d, data);
		putchar_ameliore(i, ' ', data);
		return (0);
	}
	if ((data->width > nbd && data->zero) && !data->dot)
	{
		if (data->d < 0)
		{
			putchar_len('-', data);
			data->moins = '-';
		}
		putchar_ameliore(i, '0', data);
	}
	else if (data->width > nbd && data->zero && \
			data->dot && data->precision >= nbd)
		putchar_ameliore(i, '0', data);
	else if (data->width > nbd && !data->minus)
		putchar_ameliore(i, ' ', data);
	case_5_d(nbd, j, data);
	return (0);
}

int		case_5_d(long int nbd, int j, t_data *data)
{
	if (data->precision >= nbd)
	{
		if (data->d < 0)
		{
			putchar_len('-', data);
			putchar_len('0', data);
			data->moins = '-';
		}
		putchar_ameliore(j, '0', data);
	}
	if (data->precision == 0 && data->d == 0 && data->width > 0 && data->dot)
		putchar_len(' ', data);
	if (data->precision == 0 && data->d == 0 && data->dot)
		return (0);
	putnbr(data->d, data);
	return (0);
}

int		case_2_d(int i, int j, t_data *data)
{
	if (data->d < 0)
	{
		putchar_len('-', data);
		putchar_len('0', data);
		data->moins = '-';
	}
	putchar_ameliore(j, '0', data);
	putnbr(data->d, data);
	if (data->d < 0)
		j = j + 1;
	putchar_ameliore(i - j, ' ', data);
	return (0);
}

int		case_3_d(int i, int j, t_data *data)
{
	if (data->width > data->precision && !data->minus)
	{
		if (data->d < 0)
			putchar_ameliore(i - (j + 1), ' ', data);
		else
			putchar_ameliore(i - j, ' ', data);
		if (data->d < 0)
		{
			putchar_len('-', data);
			putchar_len('0', data);
			data->d *= -1;
		}
		putchar_ameliore(j, '0', data);
	}
	putnbr(data->d, data);
	return (0);
}
