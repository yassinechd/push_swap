/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:29:02 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/13 20:10:23 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (1);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

void	ft_free_list(t_elem *head)
{
	t_elem	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_free_stacks(t_list **list)
{
	t_elem	*head_a;
	t_elem	*head_b;
	t_elem	*tmp;

	if (list && *list)
	{
		head_a = (*list)->head_a;
		head_b = (*list)->head_b;
		while (head_a)
		{
			tmp = head_a;
			head_a = head_a->next;
			free(tmp);
		}
		while (head_b)
		{
			tmp = head_b;
			head_b = head_b->next;
			free(tmp);
		}
		free(*list);
		*list = NULL;
	}
}

// dispatch
void	ft_dispatch_alg(t_list **listes)
{
	if ((*listes)->stacklen_a == 2)
		ft_sort_2(listes);
	if ((*listes)->stacklen_a == 3)
		ft_sort_3(listes);
	if ((*listes)->stacklen_a == 4)
		ft_sort_4(listes);
	if ((*listes)->stacklen_a == 5)
		ft_sort_5(listes);
	if ((*listes)->stacklen_a > 5)
		ft_ultimalgo(listes);
}

// main
int	main(int ac, char **av)
{
	t_list	*listes;
	char	**s;

	s = NULL;
	listes = ft_init_listes();
	if (ac == 0 || av[0] == NULL || av[1] == NULL)
		return (1);
	if (ac == 2)
		s = ft_split(av[1], ' ');
	if (ac > 2)
		s = av + 1;
	if (ft_check(s) != 0)
	{
		if (ac == 2 && s != NULL)
			return (ft_free(s));
		free(listes);
		return (1);
	}
	ft_fill_stack(s, &listes);
	if (ac == 2 && s != NULL)
		ft_free(s);
	ft_update_len_and_index(&listes);
	ft_dispatch_alg(&listes);
	ft_free_stacks(&listes);
}
