/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:29:15 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 16:37:06 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(int c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_check_double(char **s)
{
	int	i;
	int	j;
	int	vue;

	i = 0;
	while (s[i])
	{
		vue = ft_atoi(s[i]);
		j = i + 1;
		while (s[j])
		{
			if (ft_atoi(s[j]) == vue)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_sign(char *s)
{
	int	i;
	int	signe;

	signe = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			signe++;
		if (signe == 2)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check(char **s)
{
	int	i;
	int	j;
	int	signe_db;

	signe_db = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (ft_isnum(s[i][j]) == 0)
				return (write(1, "ERROR PRAM", 10));
			j++;
		}
		if (ft_check_sign(s[i]) == 0)
			return (write(1, "ERROR PRAM", 10));
		i++;
	}
	if (ft_check_double(s) == 0)
		return (write(1, "ERROR PRAM", 10));
	ft_check_double(s);
	return (0);
}

int	ft_is_list_sorted(t_list **list_a)
{
	t_elem	*head;

	if (!list_a || !(*list_a) || !(*list_a)->head)
		return (1);
	head = (*list_a)->head;
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
