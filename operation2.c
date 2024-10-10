/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:14:01 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 16:22:04 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **list_a)
{
	t_elem	*top;
	t_elem	*next;

	if (*list_a == NULL || (*list_a)->head == NULL
		|| (*list_a)->head->next == NULL)
		return ;
	top = (*list_a)->head;
	next = top->next;
	top->next = next->next;
	next->next = top;
	(*list_a)->head = next;
	ft_update_index(&(*list_a));
	ft_printf("sa\n");
}

void	swap_b(t_list **list_b)
{
	t_elem	*top;
	t_elem	*next;

	if (*list_b == NULL || (*list_b)->head == NULL
		|| (*list_b)->head->next == NULL)
		return ;
	top = (*list_b)->head;
	next = top->next;
	top->next = next->next;
	next->next = top;
	(*list_b)->head = next;
	ft_update_index(&(*list_b));
	ft_printf("sb\n");
}

void	push_a(t_list **list_a, t_list **list_b, t_utils *utils)
{
	t_elem	*top_b;

	if (*list_b == NULL || (*list_b)->head == NULL)
		return ;
	top_b = (*list_b)->head;
	(*list_b)->head = top_b->next;
	top_b->next = (*list_a)->head;
	(*list_a)->head = top_b;
	utils->stacklen_a = list_size(list_a);
	if (utils->stacklen_a > 0)
		utils->moyenne = list_values(list_a) / utils->stacklen_a;
	else
		utils->moyenne = 0;
	ft_update_index(list_a);
	ft_moyenne_noed(list_a, utils->moyenne);
	utils->stacklen_b = list_size(list_b);
	if (utils->stacklen_b > 0)
		utils->moyenne = list_values(list_b) / utils->stacklen_b;
	else
		utils->moyenne = 0;
	ft_update_index(list_b);
	ft_moyenne_noed(list_b, utils->moyenne);
	ft_printf("pa\n");
}

void	push_b(t_list **list_a, t_list **list_b, t_utils *utils)
{
	t_elem	*top_a;

	if (*list_a == NULL || (*list_a)->head == NULL)
		return ;
	if (!init_b_if_null(list_b))
		return ;
	top_a = (*list_a)->head;
	(*list_a)->head = top_a->next;
	top_a->next = (*list_b)->head;
	(*list_b)->head = top_a;
	utils->stacklen_a = list_size(list_a);
	if (utils->stacklen_a > 0)
		utils->moyenne = list_values(list_a) / utils->stacklen_a;
	else
		utils->moyenne = 0;
	ft_update_index(list_a);
	ft_moyenne_noed(list_a, utils->moyenne);
	utils->stacklen_b = list_size(list_b);
	if (utils->stacklen_b > 0)
		utils->moyenne = list_values(list_b) / utils->stacklen_b;
	else
		utils->moyenne = 0;
	ft_update_index(list_b);
	ft_moyenne_noed(list_b, utils->moyenne);
	ft_printf("pb\n");
}
