/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:02:46 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/06 20:56:07 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **list)
{
	t_elem	*top;
	t_elem	*next;

	if (*list == NULL || (*list)->head_a == NULL
		|| (*list)->head_a->next == NULL)
		return ;
	top = (*list)->head_a;
	next = top->next;
	top->next = next->next;
	next->next = top;
	(*list)->head_a = next;
	ft_update_len_and_index(list);
	ft_printf("sa\n");
}

void	swap_b(t_list **list)
{
	t_elem	*top;
	t_elem	*next;

	if (*list == NULL || (*list)->head_b == NULL
		|| (*list)->head_b->next == NULL)
		return ;
	top = (*list)->head_b;
	next = top->next;
	top->next = next->next;
	next->next = top;
	(*list)->head_b = next;
	ft_update_len_and_index(list);
	ft_printf("sb\n");
}

void	push_a(t_list **list)
{
	t_elem	*top_b;

	if (*list == NULL || (*list)->head_a == NULL)
		return ;
	top_b = (*list)->head_b;
	(*list)->head_b = top_b->next;
	top_b->next = (*list)->head_a;
	(*list)->head_a = top_b;
	ft_update_len_and_index(list);
	ft_printf("pa\n");
}

void	push_b(t_list **list)
{
	t_elem	*top_a;

	if (*list == NULL || (*list)->head_a == NULL)
		return ;
	top_a = (*list)->head_a;
	(*list)->head_a = top_a->next;
	if ((*list)->head_b == NULL)
		top_a->next = NULL;
	else
		top_a->next = (*list)->head_b;
	(*list)->head_b = top_a;
	ft_update_len_and_index(list);
	ft_printf("pb\n");
}

void	rotate_a(t_list **list, int i)
{
	t_elem	*top;
	t_elem	*last;

	if (*list == NULL || (*list)->head_a == NULL
		|| (*list)->head_a->next == NULL)
		return ;
	top = (*list)->head_a;
	last = (*list)->head_a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	(*list)->head_a = top->next;
	last->next = top;
	top->next = NULL;
	ft_update_len_and_index(list);
	if (i == 1)
		ft_printf("ra\n");
}
