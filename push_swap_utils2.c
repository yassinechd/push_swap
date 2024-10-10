/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:15:57 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 22:23:59 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_b_if_null(t_list **list)
{
	if (*list == NULL)
	{
		*list = malloc(sizeof(t_list));
		if (*list == NULL)
			return (0);
		(*list)->head = NULL;
	}
	return (1);
}

void	ft_init_stack_a(char **s, t_list **stack_a)
{
	int	i;

	i = 0;
	while (s[i])
	{
		add_elem((&(*stack_a)), ft_atoi(s[i]));
		i++;
	}
	ft_update_index(stack_a);
}

t_list	*ft_init(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	return (list);
}

void	ft_find_bf(t_list **list_a, t_list **list_b)
{
	int		tmp;
	t_elem	*head_a;
	t_elem	*head_b;

	head_b = (*list_b)->head;
	while (head_b)
	{
		tmp = -1;
		head_a = (*list_a)->head;
		while (head_a)
		{
			if (head_a->value > head_b->value)
			{
				if (tmp == -1 || head_a->value < (*list_a)->head->value)
					tmp = head_a->index;
			}
			head_a = head_a->next;
		}
		if (tmp != -1)
			head_b->best = tmp;
		head_b = head_b->next;
	}
}


void	ft_median_upt(t_list **list_a, t_list **list_b, t_utils *utils)
{
	t_elem	*head_a;
	t_elem	*head_b;
	int		median_value_a;
	int		median_value_b;
	int		i;

	head_a = (*list_a)->head;
	head_b = (*list_b)->head;
	// Calcul de la valeur médiane pour list_a
	median_value_a = 0;
	i = 0;
	while (head_a && i < utils->stacklen_a)
	{
		median_value_a += head_a->value; // Somme des valeurs
		head_a = head_a->next;
		i++;
	}
	median_value_a /= utils->stacklen_a; // Calcul de la médiane
	// Mise à jour de la médiane pour list_a
	head_a = (*list_a)->head; // Réinitialiser pour le parcours
	i = 0;
	while (head_a && i < utils->stacklen_a)
	{
		if (head_a->value >= median_value_a)
			head_a->mediane = 1;
		else
			head_a->mediane = 0;
		head_a = head_a->next;
		i++;
	}
	// Calcul de la valeur médiane pour list_b
	median_value_b = 0;
	i = 0;
	while (head_b && i < utils->stacklen_b)
	{
		median_value_b += head_b->value; // Somme des valeurs
		head_b = head_b->next;
		i++;
	}
	median_value_b /= utils->stacklen_b; // Calcul de la médiane
	// Mise à jour de la médiane pour list_b
	head_b = (*list_b)->head; // Réinitialiser pour le parcours
	i = 0;
	while (head_b && i < utils->stacklen_b)
	{
		if (head_b->value >= median_value_b)
			head_b->mediane = 1;
		else
			head_b->mediane = 0;
		head_b = head_b->next;
		i++;
	}
}
