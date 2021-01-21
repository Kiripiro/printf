/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:06:27 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 16:01:48 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_s(t_data *data)
{
	int nbc;
	int i;

	nbc = (int)ft_strlen(data->s);
	i = data->width - nbc;
	if (!data->minus)
	{
		if (data->width <= nbc || (data->precision >= nbc \
					|| !data->dot))
			case_1_s(nbc, i, data);
		else if (data->width > nbc && data->precision < nbc)
			case_2_s(0, data);
	}
	else
	{
		if (data->width <= nbc || (data->precision >= nbc \
					|| !data->dot))
			case_3_s(nbc, i, data);
		else if (data->width > nbc && data->precision < nbc)
			case_4_s(0, data);
	}
}

void	case_1_s(int nbc, int i, t_data *data)
{
	if (data->width > nbc)
	{
		putchar_ameliore(i, ' ', data);
		putstr_len(data->s, data);
	}
	else if (data->precision >= 0 && data->precision < nbc && data->dot)
	{
		putchar_ameliore((data->width - data->precision), ' ', data);
		i = 0;
		while (i < data->precision)
		{
			putchar_len(data->s[i], data);
			i++;
		}
	}
	else
		putstr_len(data->s, data);
}

void	case_2_s(int i, t_data *data)
{
	while (i < (data->width - data->precision))
	{
		putchar_len(' ', data);
		i++;
	}
	i = 0;
	while (i < data->precision)
	{
		putchar_len(data->s[i], data);
		i++;
	}
}

void	case_3_s(int nbc, int i, t_data *data)
{
	if (data->width > nbc)
	{
		putstr_len(data->s, data);
		putchar_ameliore(i, ' ', data);
	}
	else if (data->precision >= 0 && data->precision < nbc && data->dot)
	{
		i = 0;
		while (i < data->precision)
		{
			putchar_len(data->s[i], data);
			i++;
		}
		putchar_ameliore((data->width - data->precision), ' ', data);
	}
	else
		putstr_len(data->s, data);
}

void	case_4_s(int i, t_data *data)
{
	while (i < data->precision)
	{
		putchar_len(data->s[i], data);
		i++;
	}
	i = 0;
	while (i < (data->width - data->precision))
	{
		putchar_len(' ', data);
		i++;
	}
}
