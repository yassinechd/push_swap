/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:16:46 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 21:47:02 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ultimalgo(t_list **list_a, t_list **list_b, t_utils *utils)
{
	t_elem	*head;

	while (utils->stacklen_a > 5)
	{
		head = (*list_a)->head;
		if (head->moyenne == 0)
			push_b(list_a, list_b, utils);
		else if (head->moyenne == 1)
			rotate_a(list_a);
	}
	if (utils->stacklen_a == 5)
		ft_sort_5(list_a, list_b, utils);
	ft_find_bf(list_a, list_b);
	ft_median_upt(list_a, list_b, utils);
	ft_update_cost_top(list_a, list_b, utils);
	ft_update_cost(list_a, list_b);
	while (utils->stacklen_b > 0)
		ft_push_to_bf(list_a, list_b, utils);
	sort_stack(list_a);
}
