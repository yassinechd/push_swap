/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_update2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:04:53 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/06 21:06:07 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mediane_w_index(t_list **list)
{
	t_elem	*head;
	int		mediane;

	mediane = 0;
	head = (*list)->head_a;
	while (head)
	{
		if (head->index == (*list)->min)
			mediane = head->mediane;
		head = head->next;
	}
	(*list)->mediane_of_min = mediane;
}

void	ft_min(t_list **list)
{
	int		min;
	int		mediane;
	int		value;
	t_elem	*head;

	if (list == NULL || *list == NULL || (*list)->head_a == NULL)
		return ;
	head = (*list)->head_a;
	min = head->index;
	value = head->value;
	while (head)
	{
		if (head->value < value)
		{
			mediane = head->mediane;
			min = head->index;
			value = head->value;
		}
		head = head->next;
	}
	(*list)->min = min;
	(*list)->mediane_of_min2 = mediane;
	ft_mediane_w_index(list);
}

void	ft_update_cost(t_list **list)
{
	t_elem	*head_a;
	t_elem	*head_b;
	t_elem	*bestfriend;

	head_b = (*list)->head_b;
	while (head_b)
	{
		head_a = (*list)->head_a;
		bestfriend = NULL;
		while (head_a)
		{
			if (head_a->index == head_b->bestfriend)
			{
				bestfriend = head_a;
				break ;
			}
			head_a = head_a->next;
		}
		if (bestfriend)
			head_b->cost_to_bf = head_b->cost_to_top + bestfriend->cost_to_top;
		else
			head_b->cost_to_bf = head_b->cost_to_top;
		head_b = head_b->next;
	}
}

void	ft_update_cost_top(t_list **list)
{
	t_elem	*head_a;
	t_elem	*head_b;

	head_a = (*list)->head_a;
	head_b = (*list)->head_b;
	while (head_a)
	{
		if (head_a->mediane == 0)
			head_a->cost_to_top = head_a->index;
		else if (head_a->mediane == 1)
			head_a->cost_to_top = (*list)->stacklen_a - head_a->index;
		head_a = head_a->next;
	}
	while (head_b)
	{
		if (head_b->mediane == 0)
			head_b->cost_to_top = head_b->index;
		else if (head_b->mediane == 1)
			head_b->cost_to_top = (*list)->stacklen_b - head_b->index;
		head_b = head_b->next;
	}
}

void	ft_the_big_up(t_list **list)
{
	ft_update_len_and_index(list);
	ft_update_cost_top(list);
	ft_update_cost(list);
	ft_find_bf(list);
}
