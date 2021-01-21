/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:38:17 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 16:08:42 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	digit_treatment(t_data *data, va_list args)
{
	if (data->str[data->i] == '0' && data->str[data->i + 1] == '-')
	{
		data->i++;
		minus_treatment(data, args);
		return ;
	}
	else if (data->str[data->i] == '0')
		digit_treatment_bis(data, args);
	else
	{
		if (!data->zero)
			data->sp = 1;
		while (ft_isdigit(data->str[data->i]))
			data->width = data->width * 10 + data->str[data->i++] - 48;
	}
	if (data->str[data->i] == '-')
	{
		data->zero = 0;
		minus_treatment(data, args);
		return ;
	}
	if (data->str[data->i] == '.')
		dot_treatment(data, args);
	else if (is_specifier(data->str[data->i]))
		len_arg(data->str[data->i], data, args);
}

void	digit_treatment_bis(t_data *data, va_list args)
{
	data->zero = 1;
	while (data->str[data->i] == '0')
		data->i++;
	if (data->str[data->i] == '*')
	{
		data->width = va_arg(args, int);
		data->i++;
		if (data->width < 0)
		{
			data->zero = 0;
			data->minus = 1;
			data->width *= -1;
		}
	}
	else
		while (ft_isdigit(data->str[data->i]))
			data->width = data->width * 10 + data->str[data->i++] - 48;
}
