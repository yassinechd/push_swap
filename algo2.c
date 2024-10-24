/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:11:21 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/06 21:36:01 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*find_min_cost_elem(t_elem *head_b)
{
	t_elem	*min_cost_elem;

	min_cost_elem = NULL;
	while (head_b)
	{
		if (min_cost_elem == NULL
			|| head_b->cost_to_bf < min_cost_elem->cost_to_bf)
			min_cost_elem = head_b;
		head_b = head_b->next;
	}
	return (min_cost_elem);
}

t_elem	*find_bestfriend(t_list **list, int bestfriend_value)
{
	t_elem	*current;

	current = (*list)->head_a;
	while (current)
	{
		if (current->value == bestfriend_value)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	ft_push_to_bf(t_list **list)
{
	t_elem	*head_b;

	head_b = (*list)->head_b;
	if (ft_min_cost(list) == 1)
		push_a(list);
	ft_the_big_up(list);
}

void	ft_sort_stack(t_list **list)
{
	t_elem	*head_a;

	head_a = (*list)->head_a;
	ft_min(list);
	while ((*list)->min != 0)
	{
		if ((*list)->mediane_of_min2 == 0)
		{
			rotate_a(list, 1);
			(*list)->min--;
		}
		else if ((*list)->mediane_of_min2 == 1)
		{
			(*list)->min++;
			reverse_ra(list, 1);
			if ((*list)->min >= (*list)->stacklen_a)
				(*list)->min = 0;
		}
	}
}
