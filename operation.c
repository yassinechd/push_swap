/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:29:44 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 16:22:33 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **list_a)
{
	t_elem	*top;
	t_elem	*last;

	if (*list_a == NULL || (*list_a)->head == NULL
		|| (*list_a)->head->next == NULL)
		return ;
	top = (*list_a)->head;
	last = (*list_a)->head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	(*list_a)->head = top->next;
	last->next = top;
	top->next = NULL;
	ft_update_index(&(*list_a));
	ft_printf("ra\n");
}

void	rotate_b(t_list **list_b)
{
	t_elem	*top;
	t_elem	*last;

	if (*list_b == NULL || (*list_b)->head == NULL
		|| (*list_b)->head->next == NULL)
		return ;
	top = (*list_b)->head;
	last = (*list_b)->head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	(*list_b)->head = top->next;
	last->next = top;
	top->next = NULL;
	ft_update_index(&(*list_b));
	ft_printf("rb\n");
}

void	reverse_ra(t_list **list_a)
{
	t_elem	*top;
	t_elem	*prev;
	t_elem	*bot;

	if (*list_a == NULL || (*list_a)->head == NULL
		|| (*list_a)->head->next == NULL)
		return ;
	top = (*list_a)->head;
	bot = (*list_a)->head;
	prev = NULL;
	while (bot->next != NULL)
	{
		prev = bot;
		bot = bot->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	bot->next = top;
	(*list_a)->head = bot;
	ft_update(&(*list_a), 'a');
	ft_printf("rra\n");
}

void	reverse_rb(t_list **list_b)
{
	t_elem	*top;
	t_elem	*prev;
	t_elem	*bot;

	if (*list_b == NULL || (*list_b)->head == NULL
		|| (*list_b)->head->next == NULL)
		return ;
	top = (*list_b)->head;
	bot = (*list_b)->head;
	prev = NULL;
	while (bot->next != NULL)
	{
		prev = bot;
		bot = bot->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	bot->next = top;
	(*list_b)->head = bot;
	ft_update(&(*list_b), 'b');
	ft_printf("rrb\n");
}
