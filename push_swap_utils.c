/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:12:08 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/13 01:14:14 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void ft_update_index(t_list **list)
{
	int i;
	t_elem *head;

	i = 0;
	head = (*list)->head;
	while(head)
	{
		head->index = i;
		head = head->next;
		i++;
	}
}

int ft_min(t_list **list)
{
    int     min;
    int     value;
    t_elem  *head;

    // Vérification si la liste est valide
    if (list == NULL || *list == NULL || (*list)->head == NULL)
    {
        printf("Erreur : liste invalide ou vide.\n");
        return (-1);  // Utiliser -1 ou une autre valeur d'erreur
    }
    head = (*list)->head;
    min = head->index;
    value = head->value;
    while (head)
    {
        if (head->value < value)
        {
            min = head->index;
            value = head->value;
        }
        head = head->next;
    }
    return (min);
}

void ft_moyenne_noed(t_list **list, int moyenne) // Passer la moyenne comme argument
{
    t_elem  *head;

    if (list == NULL || *list == NULL)
        return; // Vérifie que la liste est valide

    head = (*list)->head;

    // Parcourir la liste et comparer chaque valeur avec la moyenne
    while (head)
    {
        if (head->value <= moyenne)
            head->moyenne = 0;
        else
            head->moyenne = 1;
        head = head->next;
    }
}
