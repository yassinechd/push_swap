/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:32:16 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/06 21:36:34 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_list_sorted(t_list **list)
{
	t_elem	*head;

	if (!list || !(*list) || !(*list)->head_a)
		return (0);
	head = (*list)->head_a;
	while (head && head->next)
	{
		if (head->value > head->next->value)
		{
			return (0);
		}
		head = head->next;
	}
	return (1);
}

int	ft_find_bestfriend(t_list **list, int bestfriend, int *index_bf,
		int *mediane)
{
	t_elem	*head_a;

	head_a = (*list)->head_a;
	*index_bf = -1;
	*mediane = 0;
	while (head_a)
	{
		if (head_a->value == bestfriend)
		{
			*index_bf = head_a->index;
			*mediane = head_a->mediane;
			return (1);
		}
		head_a = head_a->next;
	}
	return (-1);
}

void	ft_rotate_to_bestfriend(t_list **list, int *index_bf, int *mediane)
{
	while (*index_bf != 0)
	{
		if (*mediane == 0)
		{
			rotate_a(list, 1);
			(*index_bf)--;
		}
		else if (*mediane == 1)
		{
			reverse_ra(list, 1);
			(*index_bf)++;
			if (*index_bf >= (*list)->stacklen_a)
				*index_bf = 0;
		}
	}
}

int	ft_up_the_bf(t_list **list, int bestfriend)
{
	int	index_bf;
	int	mediane;

	if (ft_find_bestfriend(list, bestfriend, &index_bf, &mediane) == -1)
		return (-1);
	ft_rotate_to_bestfriend(list, &index_bf, &mediane);
	return (1);
}
