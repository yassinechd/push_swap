/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:19:15 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 16:21:29 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rr(t_list **list_a, t_list **list_b)
{
	reverse_ra(list_a);
	reverse_rb(list_b);
}

void	swap_swap(t_list **list_a, t_list **list_b)
{
	swap_a(list_a);
	swap_b(list_b);
}

void	rotate_rotate(t_list **list_a, t_list **list_b)
{
	rotate_a(list_a);
	rotate_b(list_b);
}
