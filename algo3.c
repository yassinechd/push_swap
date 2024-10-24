/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:14:38 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/17 02:44:02 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_bf(t_list **list)
{
	int		tmp;
	t_elem	*head_a;
	t_elem	*head_b;

	head_b = (*list)->head_b;
	while (head_b)
	{
		tmp = -1;
		head_a = (*list)->head_a;
		while (head_a)
		{
			if (head_a->value > head_b->value)
			{
				if (tmp == -1 || head_a->value < tmp)
					tmp = head_a->value;
			}
			head_a = head_a->next;
		}
		if (tmp != -1)
			head_b->bestfriend = tmp;
		head_b = head_b->next;
	}
}

void	ft_find_min_cost(t_list **list)
{
	t_elem	*head_b;

	(*list)->cost_alg = -1;
	(*list)->index_alg = 0;
	(*list)->mediane_alg = 0;
	(*list)->bestfriend_alg = 0;
	head_b = (*list)->head_b;
	while (head_b)
	{
		if ((*list)->cost_alg == -1 || (*list)->cost_alg > head_b->cost_to_bf)
		{
			(*list)->cost_alg = head_b->cost_to_bf;
			(*list)->index_alg = head_b->index;
			(*list)->mediane_alg = head_b->mediane;
			(*list)->bestfriend_alg = head_b->bestfriend;
		}
		head_b = head_b->next;
	}
}

void	ft_rotate_based_on_index(t_list **list)
{
	while ((*list)->index_alg != 0)
	{
		if ((*list)->mediane_alg == 0)
		{
			rotate_b(list, 1);
			(*list)->index_alg--;
		}
		else if ((*list)->mediane_alg == 1)
		{
			reverse_rb(list, 1);
			(*list)->index_alg++;
			if ((*list)->index_alg >= (*list)->stacklen_b)
				(*list)->index_alg = 0;
		}
	}
}

int	ft_min_cost(t_list **list)
{
	ft_find_min_cost(list);
	ft_rotate_based_on_index(list);
	if (ft_up_the_bf(list, (*list)->bestfriend_alg) == 1)
		return (1);
	return (0);
}
