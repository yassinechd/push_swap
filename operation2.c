/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:52:15 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/06 20:56:50 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **list)
{
	reverse_ra(list, 0);
	reverse_rb(list, 0);
	ft_printf("rrr");
}

void	rr(t_list **list)
{
	rotate_a(list, 0);
	rotate_b(list, 0);
	ft_printf("rr");
}

void	reverse_rb(t_list **list, int i)
{
	t_elem	*top;
	t_elem	*prev;
	t_elem	*bot;

	if (*list == NULL || (*list)->head_b == NULL
		|| (*list)->head_b->next == NULL)
		return ;
	top = (*list)->head_b;
	bot = (*list)->head_b;
	prev = NULL;
	while (bot->next != NULL)
	{
		prev = bot;
		bot = bot->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	bot->next = top;
	(*list)->head_b = bot;
	ft_update_len_and_index(list);
	if (i == 1)
		ft_printf("rrb\n");
}

void	reverse_ra(t_list **list, int i)
{
	t_elem	*top;
	t_elem	*prev;
	t_elem	*bot;

	if (*list == NULL || (*list)->head_a == NULL
		|| (*list)->head_a->next == NULL)
		return ;
	top = (*list)->head_a;
	bot = (*list)->head_a;
	prev = NULL;
	while (bot->next != NULL)
	{
		prev = bot;
		bot = bot->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	bot->next = top;
	(*list)->head_a = bot;
	ft_update_len_and_index(list);
	if (i == 1)
		ft_printf("rra\n");
}

void	rotate_b(t_list **list, int i)
{
	t_elem	*top;
	t_elem	*last;

	if (*list == NULL || (*list)->head_b == NULL
		|| (*list)->head_b->next == NULL)
		return ;
	top = (*list)->head_b;
	last = (*list)->head_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	(*list)->head_b = top->next;
	last->next = top;
	top->next = NULL;
	ft_update_len_and_index(list);
	if (i == 1)
		ft_printf("rb\n");
}
