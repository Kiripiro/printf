/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:31:00 by atourret          #+#    #+#             */
/*   Updated: 2020/11/27 14:58:50 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;
	t_list *temp;

	current = *lst;
	temp = 0;
	while (current)
	{
		if (current->next)
			temp = current->next;
		else
			temp = 0;
		del(current->content);
		free(current);
		current = temp;
	}
	*lst = 0;
}
