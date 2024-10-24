/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:19:57 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/06 21:06:37 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*fonction dediee pour calculer la mediane*/
int	calc_mediane(int stacklen)
{
	if (stacklen % 2 == 0)
		return (stacklen / 2 - 1);
	else
		return (stacklen / 2);
}

void	ft_mediane_noed(t_list **list)
{
	t_elem	*head_a;
	t_elem	*head_b;

	if (list == NULL || *list == NULL)
		return ;
	(*list)->mediane_a = calc_mediane((*list)->stacklen_a);
	(*list)->mediane_b = calc_mediane((*list)->stacklen_b);
	head_a = (*list)->head_a;
	while (head_a)
	{
		if (head_a->index <= (*list)->mediane_a)
			head_a->mediane = 0;
		else
			head_a->mediane = 1;
		head_a = head_a->next;
	}
	head_b = (*list)->head_b;
	while (head_b)
	{
		if (head_b->index <= (*list)->mediane_b)
			head_b->mediane = 0;
		else
			head_b->mediane = 1;
		head_b = head_b->next;
	}
}

void	ft_moyenne_noed(t_list **list)
{
	t_elem	*head_a;

	if (list == NULL || *list == NULL)
		return ;
	head_a = (*list)->head_a;
	while (head_a)
	{
		if (head_a->value <= (*list)->moyenne)
			head_a->moyenne = 0;
		else
			head_a->moyenne = 1;
		head_a = head_a->next;
	}
}

// met a jour la somme et la mediane par noeud
void	ft_update_moyenne(t_list **list)
{
	int	somme;

	somme = list_values(list);
	if ((*list)->stacklen_a == 0)
		return ;
	(*list)->moyenne = somme / (*list)->stacklen_a;
	ft_mediane_noed(list);
	ft_moyenne_noed(list);
}

void	ft_update_len_and_index(t_list **list)
{
	t_elem	*head_a;
	t_elem	*head_b;
	int		i;

	if (list == NULL || *list == NULL)
		return ;
	i = 0;
	head_a = (*list)->head_a;
	while (head_a)
	{
		head_a->index = i;
		head_a = head_a->next;
		i++;
	}
	(*list)->stacklen_a = i;
	i = 0;
	head_b = (*list)->head_b;
	while (head_b)
	{
		head_b->index = i;
		head_b = head_b->next;
		i++;
	}
	(*list)->stacklen_b = i;
	ft_update_moyenne(list);
}
