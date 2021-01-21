/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <atourret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:07:03 by atourret          #+#    #+#             */
/*   Updated: 2021/01/21 16:18:01 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_data
{
	int				dot;
	int				minus;
	int				zero;
	int				percent;
	int				sp;
	int				width;
	int				precision;
	int				i;
	int				len;
	char			*str;
	int				negative;
	int				d;
	char			c;
	int				intc;
	char			moins;
	unsigned long	adr;
	int				end;
	void			*p;
	int				first;
	int				x;
	char			type;
	char			*s;
	int				u2;
	int				index;
}				t_data;

int				ft_printf(const char *str, ...) __attribute__
					((format(printf,1,2)));
void			init_flags(t_data *data);

int				pre_treatment(t_data *data, va_list args);
int				minus_treatment(t_data *data, va_list args);
void			digit_treatment(t_data *data, va_list args);
void			digit_treatment_bis(t_data *data, va_list args);
void			dot_treatment(t_data *data, va_list args);
int				star_treatment(t_data *data, va_list args);

void			print(char *res, t_data *data, char c);
void			print_spec(t_data *data, va_list args);

int				len_arg(char c, t_data *data, va_list args);
int				len_arg_bis(char c, t_data *data, va_list args);

void			print_c(t_data *data);
int				case_1_c(t_data *data);

void			print_d(t_data *data);
int				case_1_d(long int nbd, int i, int j, t_data *data);
int				case_2_d(int i, int j, t_data *data);
int				case_3_d(int i, int j, t_data *data);
int				case_4_d(int j, t_data *data);
int				case_5_d(long int nbd, int j, t_data *data);

void			print_p(t_data *data);
void			case_1_p(t_data *data, char *charp);
void			case_2_p(t_data *data, char *charp);

void			print_r(t_data *data, char *str);
void			case_1_r(t_data *data, int i, char *str);

void			print_s(t_data *data);
void			case_1_s(int nbc, int i, t_data *data);
void			case_2_s(int i, t_data *data);
void			case_3_s(int nbc, int i, t_data *data);
void			case_4_s(int i, t_data *data);

int				print_u(t_data *data);
int				case_1_u(int nbd, int i, int j, t_data *data);
int				case_2_u(int i, int j, t_data *data);

void			print_x(t_data *data);
void			positive_x(t_data *data, char *base);
void			negative_x(t_data *data, unsigned int ux, char *base);
int				case_1_x(int nbd, int j, t_data *data, char *charx);
int				case_2_x(int i, int j, t_data *data, char *charx);

void			print_spec(t_data *data, va_list args);
void			print_int(t_data *data, va_list args);
void			print_hexa(t_data *data, va_list args);

int				unsigned_nbd(unsigned long int nb);
int				nbx(unsigned long i);
void			putnbr(long int nb, t_data *data);
void			putnbr_unsigned(unsigned int nb, t_data *data);
void			putchar_ameliore(int end, char c, t_data *data);
int				nb_d(long int nb, t_data *data);
int				is_flags(char c);
int				is_specifier(char c);
void			putchar_len(char c, t_data *data);
void			putstr_len(char *str, t_data *data);

#endif
