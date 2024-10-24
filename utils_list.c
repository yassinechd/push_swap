/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:17:48 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/07 00:23:18 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*init les listes au debut pour quelle soit allouer*/
t_list	*ft_init_listes(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head_a = NULL;
	list->head_b = NULL;
	return (list);
}

/*avoir la somme des valeur ds la list*/
int	list_values(t_list **list)
{
	int		value;
	t_elem	*head_a;

	value = 0;
	head_a = (*list)->head_a;
	while (head_a)
	{
		value += head_a->value;
		head_a = head_a->next;
	}
	return (value);
}

void	add_elem(t_list **list, int value)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return (free(new));
	new->value = value;
	new->next = (*list)->head_a;
	(*list)->head_a = new;
	ft_update_len_and_index(list);
}

/*remplire la stack_a avec les char dans s*/
void	ft_fill_stack(char **s, t_list **listes)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		i--;
		add_elem(listes, ft_atoi(s[i]));
	}
}

/*afficher la liste*/
//void	ft_aff_list(t_list *list)
//{
//	int		i;
//	t_elem	*element_a;
//	t_elem	*element_b;

//	i = 0;
//	if (list == NULL)
//		return ;
//	element_a = list->head_a;
//	element_b = list->head_b;
//	ft_printf("Longueur de la pile a : %d\n", list->stacklen_a);
//	ft_printf("MOYENNE : %d\n", list->moyenne);
//	while (element_a != NULL)
//	{
//		ft_printf("Noeud %d = %d -- index %d, médiane %d, moyenne %d\n", i,
//			element_a->value, element_a->index, element_a->mediane,
//			element_a->moyenne);
//		i++;
//		element_a = element_a->next;
//	}
//	ft_printf("\n");
//	i = 0;
//	ft_printf("Longueur de la pile b : %d\n", list->stacklen_b);
//	while (element_b != NULL)
//	{
//		ft_printf("Noeud %d = %d -- index %d, bff -- %d\n", i, element_b->value,
//			element_b->index, element_b->bestfriend);
//		i++;
//		element_b = element_b->next;
//	}
//	ft_printf("\n");
//}