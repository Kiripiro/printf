/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:38:25 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 15:57:04 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int		star_treatment(t_data *data, va_list args)
{
	data->i++;
	data->width = va_arg(args, int);
	if (data->width < 0)
	{
		data->minus = 1;
		data->width *= -1;
	}
	if (is_specifier(data->str[data->i]))
		len_arg(data->str[data->i], data, args);
	else if (data->str[data->i] == '.')
		dot_treatment(data, args);
	return (0);
}

void	dot_treatment(t_data *data, va_list args)
{
	data->dot = 1;
	if (data->str[++data->i] == '*')
	{
		data->precision = va_arg(args, int);
		data->i++;
		if (data->precision < 0)
		{
			data->dot = 0;
			data->precision = 0;
		}
	}
	else
		while (ft_isdigit(data->str[data->i]))
			data->precision = data->precision * 10 + data->str[data->i++] - 48;
	if (is_specifier(data->str[data->i]))
		len_arg(data->str[data->i], data, args);
}

int		minus_treatment(t_data *data, va_list args)
{
	data->minus = 1;
	while (data->str[data->i] == '-' || data->str[data->i] == '0')
		data->i++;
	if (data->str[data->i] == '*')
	{
		data->width = va_arg(args, int);
		if (data->width < 0)
			data->width *= -1;
		data->i++;
	}
	else if (ft_isdigit(data->str[data->i]))
		while (ft_isdigit(data->str[data->i]))
			data->width = data->width * 10 + data->str[data->i++] - 48;
	if (data->str[data->i] == '.')
		dot_treatment(data, args);
	else if (is_specifier(data->str[data->i]))
		len_arg(data->str[data->i], data, args);
	return (0);
}

int		pre_treatment(t_data *data, va_list args)
{
	if (data->str[++data->i] == '-')
		minus_treatment(data, args);
	else if (data->str[data->i] == '.')
		dot_treatment(data, args);
	else if (data->str[data->i] == '*')
		star_treatment(data, args);
	else if (ft_isdigit(data->str[data->i]))
		digit_treatment(data, args);
	else if (data->str[data->i] == '%')
	{
		ft_putchar_fd('%', 1);
		data->len++;
	}
	else if (is_specifier(data->str[data->i]))
		print_spec(data, args);
	return (0);
}
