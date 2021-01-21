/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:09:26 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 16:18:38 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_hexa(t_data *data, va_list args)
{
	if (data->type == 'x' || data->type == 'X')
	{
		data->x = va_arg(args, int);
		print_x(data);
	}
	else if (data->type == 'p')
	{
		data->p = va_arg(args, void*);
		data->adr = (unsigned long)data->p;
		data->end = nbx(data->adr) + 1;
		print_p(data);
	}
}

void	print_int(t_data *data, va_list args)
{
	char	c;

	c = data->str[data->i];
	if (c == 'd' || c == 'i')
	{
		data->moins = 'x';
		putnbr(va_arg(args, int), data);
	}
	else if (c == 'u')
		putnbr(va_arg(args, unsigned int), data);
}

void	print_spec(t_data *data, va_list args)
{
	char	c;
	char	*temp;

	temp = NULL;
	c = data->str[data->i];
	data->type = c;
	if (c == 'c')
		putchar_len(va_arg(args, int), data);
	else if (c == 's')
	{
		temp = va_arg(args, char *);
		if (temp)
			putstr_len(temp, data);
		else
			putstr_len("(null)", data);
	}
	else if (c == 'd' || c == 'i' || c == 'u')
		print_int(data, args);
	else
		print_hexa(data, args);
}
