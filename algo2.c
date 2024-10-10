/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:01:50 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 21:45:39 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*find_min_cost_elem(t_elem *head_b)
{
	t_elem	*min_cost_elem;

	min_cost_elem = NULL;
	while (head_b)
	{
		if (min_cost_elem == NULL || head_b->cost < min_cost_elem->cost)
			min_cost_elem = head_b;
		head_b = head_b->next;
	}
	return (min_cost_elem);
}

t_elem	*find_bestfriend(t_elem *head_a, int bestfriend_index)
{
	while (head_a)
	{
		if (head_a->index == bestfriend_index)
			return (head_a);
		head_a = head_a->next;
	}
	return (NULL);
}

void	ft_push_to_bf(t_list **list_a, t_list **list_b, t_utils *utils)
{
	t_elem	*head_b;
	t_elem	*min_cost_elem;
	t_elem	*bestfriend;
	int		bestfriend_index;

	head_b = (*list_b)->head;
	min_cost_elem = find_min_cost_elem(head_b);
	if (min_cost_elem)
	{
		bestfriend_index = min_cost_elem->best;
		bestfriend = find_bestfriend((*list_a)->head, bestfriend_index);
		if (bestfriend)
		{
			while ((*list_a)->head != bestfriend)
				rotate_a(list_a);
			push_a(list_a, list_b, utils);
		}
	}
	ft_find_bf(list_a, list_b);
	ft_median_upt(list_a, list_b, utils);
	ft_update_cost_top(list_a, list_b, utils);
	ft_update_cost(list_a, list_b);
}

void	insert_sorted(t_elem **sorted_head, t_elem *new_elem)
{
	t_elem	*current;

	if (*sorted_head == NULL || new_elem->value < (*sorted_head)->value)
	{
		new_elem->next = *sorted_head;
		*sorted_head = new_elem;
	}
	else
	{
		current = *sorted_head;
		while (current->next != NULL && current->next->value < new_elem->value)
			current = current->next;
		new_elem->next = current->next;
		current->next = new_elem;
	}
}

void	sort_stack(t_list **list_a)
{
	t_elem	*sorted_head;
	t_elem	*current;
	t_elem	*next;

	sorted_head = NULL;
	next = NULL;
	if (*list_a == NULL || (*list_a)->head == NULL)
		return ;
	current = (*list_a)->head;
	while (current != NULL)
	{
		next = current->next;
		insert_sorted(&sorted_head, current);
		current = next;
	}
	(*list_a)->head = sorted_head;
}
