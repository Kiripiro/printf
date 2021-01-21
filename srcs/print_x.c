/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:08:22 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 16:03:20 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_x(t_data *data)
{
	unsigned int	ux;
	char			*base;

	ux = (unsigned)data->x;
	if (data->type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (data->x >= 0)
	{
		data->end = nbx((unsigned)data->x) + 1;
		positive_x(data, base);
	}
	else
	{
		data->end = nbx(ux) + 1;
		negative_x(data, ux, base);
	}
}

void	positive_x(t_data *data, char *base)
{
	int		x;
	char	charx[data->end];

	x = data->x;
	charx[data->end] = '\0';
	data->end = data->end - 1;
	while (data->end >= 0)
	{
		charx[data->end] = (base[(x % 16)]);
		x = x / 16;
		data->end--;
	}
	x = ft_strlen(charx);
	data->index = data->width - x;
	if (data->width < x || data->precision < x)
		case_1_x(x, (data->precision - x), data, charx);
	else
		case_2_x((data->width - x), (data->precision - x), data, charx);
}

void	negative_x(t_data *data, unsigned int ux, char *base)
{
	char	charx[data->end];
	int		x;

	charx[data->end] = '\0';
	data->end = data->end - 1;
	while (data->end >= 0)
	{
		charx[data->end] = (base[(ux % 16)]);
		ux = ux / 16;
		data->end--;
	}
	x = ft_strlen(charx);
	data->index = data->width - x;
	if (data->width < x || data->precision < x)
		case_1_x(x, (data->precision - x), data, charx);
	else
		case_2_x((data->width - x), (data->precision - x), data, charx);
}

int		case_1_x(int nbd, int j, t_data *data, char *charx)
{
	if (data->width > nbd && data->minus)
	{
		if (data->precision == 0 && data->dot && data->x == 0)
			putchar_len(' ', data);
		else
			putstr_len(charx, data);
		putchar_ameliore(data->index, ' ', data);
		return (0);
	}
	if ((data->width > nbd && data->zero) && !data->dot)
		putchar_ameliore(data->index, '0', data);
	else if (data->width > nbd && !data->minus)
		putchar_ameliore(data->index, ' ', data);
	if (data->precision > nbd)
		putchar_ameliore(j, '0', data);
	if (data->precision == 0 && data->x == 0 && data->width > 0 && data->dot)
		putchar_len(' ', data);
	if (data->precision == 0 && data->x == 0 && data->dot)
		return (0);
	putstr_len(charx, data);
	return (0);
}

int		case_2_x(int i, int j, t_data *data, char *charx)
{
	if (data->width > data->precision && data->minus && data->dot)
	{
		putchar_ameliore(j, '0', data);
		putstr_len(charx, data);
		putchar_ameliore(i - j, ' ', data);
	}
	else if (data->width > data->precision && !data->minus && data->dot)
	{
		putchar_ameliore(i - j, ' ', data);
		putchar_ameliore(j, '0', data);
	}
	else
		putchar_ameliore(j, '0', data);
	if (!(data->width > data->precision && data->minus && data->dot))
		putstr_len(charx, data);
	return (0);
}
