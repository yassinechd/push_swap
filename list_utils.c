/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:29:26 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 21:19:31 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_initialisaion(int value)
{
	t_list	*list;
	t_elem	*elem;

	list = malloc(sizeof(t_list));
	elem = malloc(sizeof(t_elem));
	if (!list || !elem)
	{
		free(list);
		free(elem);
		return (NULL);
	}
	elem->value = value;
	elem->next = NULL;
	list->head = elem;
	return (list);
}

void	add_elem(t_list **list, int value)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return (free(new));
	new->value = value;
	new->next = (*list)->head;
	(*list)->head = new;
}

void	ft_aff_list(t_list *list)
{
	int		i;
	t_elem	*element;

	i = 0;
	if (list == NULL)
		return ;
	element = list->head;
	while (element != NULL)
	{
		ft_printf("noed%d = %d\n", i, element->value);
		i++;
		element = element->next;
	}
	ft_printf("\n");
}

int	list_size(t_list **list)
{
	t_elem	*head;
	int		i;

	if (list == NULL || *list == NULL || (*list)->head == NULL)
		return (0);
	i = 0;
	head = (*list)->head;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int	list_values(t_list **list)
{
	int		value;
	t_elem	*head;

	value = 0;
	head = (*list)->head;
	while (head)
	{
		value += head->value;
		head = head->next;
	}
	return (value);
}
