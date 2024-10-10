/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:29:34 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 21:42:18 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_list **list_a)
{
	if ((*list_a)->head && (*list_a)->head->next
		&& (*list_a)->head->value > (*list_a)->head->next->value)
		swap_a(list_a);
}

void	ft_sort_3(t_list **list_a, t_utils *utils)
{
	if (!list_a || !*list_a || !(*list_a)->head || !(*list_a)->head->next
		|| !(*list_a)->head->next->next)
		return ;
	utils->first = (*list_a)->head->value;
	utils->second = (*list_a)->head->next->value;
	utils->third = (*list_a)->head->next->next->value;
	if (utils->first > utils->second && utils->second < utils->third)
	{
		if (utils->first > utils->third)
			swap_a(list_a);
	}
	else if (utils->first > utils->second && utils->second > utils->third)
	{
		swap_a(list_a);
		reverse_ra(list_a);
	}
	else if (utils->first > utils->third)
		rotate_a(list_a);
	else if (utils->second > utils->third)
	{
		swap_a(list_a);
		rotate_a(list_a);
	}
	else
		reverse_ra(list_a);
}

void	ft_sort_4(t_list **list_a, t_list **list_b, t_utils *utils)
{
	int	min;

	min = ft_min(list_a);
	if (min == 0)
		return ;
	if (min == 1)
		swap_a(list_a);
	else if (min == 2)
		reverse_ra(list_a);
	else if (min >= 3)
	{
		reverse_ra(list_a);
		if (min == 4)
			reverse_ra(list_a);
	}
	push_b(list_a, list_b, utils);
	if (!ft_is_list_sorted(list_a))
		ft_sort_3(list_a, utils);
	if (min != 0)
		push_a(list_a, list_b, utils);
}

void	ft_sort_5(t_list **list_a, t_list **list_b, t_utils *utils)
{
	int	min;

	min = ft_min(list_a);
	if (min == 1)
		swap_a(list_a);
	else if (min == 2)
		rotate_a(list_a);
	else if (min >= 3)
		reverse_ra(list_a);
	if (min > 1)
		rotate_a(list_a);
	push_b(list_a, list_b, utils);
	if (min >= 2)
		rotate_a(list_a);
	ft_sort_4(list_a, list_b, utils);
	push_a(list_a, list_b, utils);
}
