/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:04:58 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 16:00:59 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_p(t_data *data)
{
	char			*base;
	char			charp[data->end];

	base = "0123456789abcdef";
	charp[data->end] = '\0';
	data->end = data->end - 1;
	while (data->end >= 0)
	{
		charp[data->end] = base[(data->adr % 16)];
		data->adr = data->adr / 16;
		data->end--;
	}
	if (data->width > (int)ft_strlen(charp))
		case_1_p(data, charp);
	else
		case_2_p(data, charp);
}

void	case_1_p(t_data *data, char *charp)
{
	if (data->minus)
	{
		case_2_p(data, charp);
		putchar_ameliore((data->width - (ft_strlen(charp) + 2)), \
				' ', data);
	}
	if (!data->minus)
	{
		putchar_ameliore((data->width - (ft_strlen(charp) + 2)), \
				' ', data);
		case_2_p(data, charp);
	}
}

void	case_2_p(t_data *data, char *charp)
{
	int i;

	i = 0;
	if ((data->p == NULL && data->precision == 0 && data->dot) && \
			data->width > 2)
		putchar_len(' ', data);
	putchar_len('0', data);
	putchar_len('x', data);
	if (data->p == NULL && data->precision == 0 && data->dot)
		return ;
	while (i < (int)ft_strlen(charp))
	{
		putchar_len(charp[i], data);
		i++;
	}
}
