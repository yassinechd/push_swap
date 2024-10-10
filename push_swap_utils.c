/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:12:08 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 21:22:40 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_tab(char **s)
{
	char	**temp;

	temp = s;
	while (*s)
	{
		free(*s);
		s++;
	}
	free(temp);
	return (0);
}

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

void	ft_update_index(t_list **list)
{
	t_elem		*head;
	int			i;

	i = 0;
	head = (*list)->head;
	while (head)
	{
		head->index = i;
		head = head->next;
		i++;
	}
}

int	ft_min(t_list **list)
{
	int		min;
	int		value;
	t_elem	*head;

	if (list == NULL || *list == NULL || (*list)->head == NULL)
		return (-1);
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

void	ft_moyenne_noed(t_list **list, int moyenne)
{
	t_elem	*head;

	if (list == NULL || *list == NULL)
		return ;
	head = (*list)->head;
	while (head)
	{
		if (head->value <= moyenne)
			head->moyenne = 0;
		else
			head->moyenne = 1;
		head = head->next;
	}
}
