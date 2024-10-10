/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:29:50 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 21:24:05 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update(t_list **list, char c)
{
	t_utils	utils;

	if (c == 'a')
	{
		utils.stacklen_a = list_size(&(*list));
		utils.moyenne = list_values(&(*list)) / utils.stacklen_a;
	}
	if (c == 'b')
		utils.stacklen_b = list_size(&(*list));
	ft_update_index(&(*list));
	ft_moyenne_noed(&(*list), utils.moyenne);
}

void	ft_dispatch_alg(t_list **stack_a, t_list **stack_b, t_utils *utils)
{
	if (utils->stacklen_a == 2)
		ft_sort_2(stack_a);
	if (utils->stacklen_a == 3)
		ft_sort_3(stack_a, utils);
	if (utils->stacklen_a == 4)
		ft_sort_4(stack_a, stack_b, utils);
	if (utils->stacklen_a == 5)
		ft_sort_5(stack_a, stack_b, utils);
	if (utils->stacklen_a > 5)
		ft_ultimalgo(stack_a, stack_b, utils);
}

void	free_list(t_list **list)
{
	t_elem	*current;
	t_elem	*next;

	if (list && *list)
	{
		current = (*list)->head;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(*list);
		*list = NULL;
	}
}

int	ft_free_all(t_list **list_a, t_list **list_b)
{
	free_list(list_a);
	free_list(list_b);
	return (0);
}

int	main(int ac, char **av)
{
	char	**s;
	t_list	*stack_a;
	t_list	*stack_b;
	t_utils	utils;

	s = NULL;
	stack_a = ft_init();
	stack_b = ft_init();
	if (ac == 0 || av[0] == NULL || av[1] == NULL)
		return (ft_free_all(&stack_a, &stack_b));
	if (ac == 2)
		s = ft_split(av[1], ' ');
	if (ac > 2)
		s = av + 1;
	if (ft_check(s) != 0)
		return (ft_free_all(&stack_a, &stack_b));
	ft_init_stack_a(s, &stack_a);
	if (ac == 2 && s != NULL)
		ft_free_tab(s);
	if (ft_is_list_sorted(&stack_a) == 1)
		return (ft_free_all(&stack_a, &stack_b));
	ft_up(&stack_a, &utils);
	ft_dispatch_alg(&stack_a, &stack_b, &utils);
	ft_free_all(&stack_a, &stack_b);
}
