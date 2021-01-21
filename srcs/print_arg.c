/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:20:04 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 16:20:06 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	len_arg_bis(char c, t_data *data, va_list args)
{
	if (c == 's')
	{
		data->s = va_arg(args, char *);
		if (!(data->s))
			data->s = "(null)";
		print_s(data);
	}
	if (c == 'u')
		data->u2 = va_arg(args, unsigned);
	if (c == 'u')
		print_u(data);
	else if (c == 'x' || c == 'X')
	{
		data->x = va_arg(args, int);
		print_x(data);
		return (0);
	}
	else if (c == 'p')
	{
		data->p = va_arg(args, void*);
		data->adr = (unsigned long)data->p;
		data->end = nbx(data->adr) + 1;
		print_p(data);
	}
	return (0);
}

int	len_arg(char c, t_data *data, va_list args)
{
	char	zero_or_sp;

	zero_or_sp = (data->zero) ? '0' : ' ';
	data->type = c;
	if (c == 'i' || c == 'd')
	{
		data->d = va_arg(args, int);
		print_d(data);
	}
	else if (c == 'c')
	{
		data->intc = va_arg(args, int);
		print_c(data);
	}
	else if (c == '%')
	{
		while (data->width-- - 1 > 0 && !data->minus)
			putchar_len(zero_or_sp, data);
		putchar_len('%', data);
		while (data->width-- > 0 && data->minus)
			putchar_len(zero_or_sp, data);
	}
	else
		len_arg_bis(c, data, args);
	return (0);
}
