/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:08:11 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/18 20:44:21 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_list **list)
{
	t_elem	*head;

	head = (*list)->head_a;
	if (head && head->next && head->value > head->next->value)
		swap_a(list);
}

void	ft_sort_3(t_list **l)
{
	if (!l || !*l || !(*l)->head_a || !(*l)->head_a->next
		|| !(*l)->head_a->next->next)
		return ;
	(*l)->f = (*l)->head_a->value;
	(*l)->s = (*l)->head_a->next->value;
	(*l)->t = (*l)->head_a->next->next->value;
	if ((*l)->f > (*l)->s && (*l)->f < (*l)->t && (*l)->s < (*l)->t)
		swap_a(l);
	else if ((*l)->f < (*l)->s && (*l)->f < (*l)->t && (*l)->s > (*l)->t)
	{
		reverse_ra(l, 1);
		swap_a(l);
	}
	else if ((*l)->f < (*l)->s && (*l)->s > (*l)->t && (*l)->f > (*l)->t)
		reverse_ra(l, 1);
	else if ((*l)->f > (*l)->s < (*l)->t && (*l)->s < (*l)->t
		&& (*l)->f > (*l)->t)
		rotate_a(l, 1);
	else if ((*l)->f > (*l)->s && (*l)->s > (*l)->t)
	{
		swap_a(l);
		reverse_ra(l, 1);
	}
}

void	ft_sort_4(t_list **list)
{
	ft_min(list);
	if ((*list)->min < 0)
		return ;
	while ((*list)->min != 0)
	{
		if ((*list)->mediane_of_min == 0)
		{
			rotate_a(list, 1);
			ft_min(list);
		}
		else if ((*list)->mediane_of_min == 1)
			reverse_ra(list, 1);
		ft_min(list);
	}
	if (ft_is_list_sorted(list))
		return ;
	push_b(list);
	if (!ft_is_list_sorted(list))
		ft_sort_3(list);
	push_a(list);
}

void	ft_sort_5(t_list **list)
{
	ft_min(list);
	if ((*list)->min < 0)
		return ;
	while ((*list)->min != 0)
	{
		if ((*list)->mediane_of_min == 0)
		{
			rotate_a(list, 1);
			ft_min(list);
		}
		else if ((*list)->mediane_of_min == 1)
			reverse_ra(list, 1);
		ft_min(list);
	}
	if (ft_is_list_sorted(list))
		return ;
	push_b(list);
	if (!ft_is_list_sorted(list))
		ft_sort_4(list);
	push_a(list);
}

void	ft_ultimalgo(t_list **list)
{
	t_elem	*head;

	ft_sort_stack(list);
	if (ft_is_list_sorted(list))
		return ;
	while ((*list)->stacklen_a > 5)
	{
		head = (*list)->head_a;
		if (head->moyenne == 0)
			push_b(list);
		else if (head->moyenne == 1)
			rotate_a(list, 1);
	}
	if ((*list)->stacklen_a == 5)
		ft_sort_5(list);
	ft_find_bf(list);
	ft_update_len_and_index(list);
	ft_update_cost_top(list);
	ft_update_cost(list);
	while ((*list)->stacklen_b > 0)
	{
		ft_push_to_bf(list);
		ft_the_big_up(list);
	}
	ft_sort_stack(list);
}
