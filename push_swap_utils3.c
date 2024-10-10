/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:25:01 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 17:54:36 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_cost_top(t_list **list_a, t_list **list_b, t_utils *utils)
{
	t_elem	*head_a;
	t_elem	*head_b;

	head_a = (*list_a)->head;
	head_b = (*list_b)->head;
	while (head_a)
	{
		if (head_a->mediane == 0)
			head_a->cost_top = head_a->index;
		else if (head_a->mediane == 1)
			head_a->cost_top = utils->stacklen_a - head_a->index;
		head_a = head_a->next;
	}
	while (head_b)
	{
		if (head_b->mediane == 0)
			head_b->cost_top = head_b->index;
		else if (head_b->mediane == 1)
			head_b->cost_top = utils->stacklen_b - head_b->index;
		head_b = head_b->next;
	}
}

void	ft_update_cost(t_list **list_a, t_list **list_b)
{
	t_elem	*head_a;
	t_elem	*head_b;
	t_elem	*bestfriend;

	head_b = (*list_b)->head;
	while (head_b)
	{
		head_a = (*list_a)->head;
		bestfriend = NULL;
		while (head_a)
		{
			if (head_a->index == head_b->best)
			{
				bestfriend = head_a;
				break ;
			}
			head_a = head_a->next;
		}
		if (bestfriend)
			head_b->cost = head_b->cost_top + bestfriend->cost_top;
		else
			head_b->cost = head_b->cost_top;
		head_b = head_b->next;
	}
}

void	ft_up(t_list **stack_a, t_utils *utils)
{
	utils->stacklen_a = list_size(stack_a);
	utils->moyenne = list_values(stack_a) / utils->stacklen_a;
	ft_moyenne_noed(stack_a, utils->moyenne);
}
