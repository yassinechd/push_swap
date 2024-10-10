/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:29:55 by yachadla          #+#    #+#             */
/*   Updated: 2024/09/29 21:22:51 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libftprintf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*def element de list chainée*/
typedef struct t_elem
{
	int				cost;
	int				cost_top;
	int				mediane;
	int				best;
	int				moyenne;
	int				index;
	int				value;
	struct t_elem	*next;
}					t_elem;

/*tete de la liste chainée*/
typedef struct t_list
{
	t_elem			*head;
}					t_list;

typedef struct t_utils
{
	int				first;
	int				second;
	int				third;
	int				moyenne;
	int				stacklen_a;
	int				stacklen_b;
}					t_utils;

/*Utils*/
int		ft_atoi(const char *str);
void	ft_moyenne_noed(t_list **list, int moyenne);
int		ft_min(t_list **list);
void	ft_update_index(t_list **list);
void	ft_find_bf(t_list **list_a, t_list **list_b);
void	ft_median_upt(t_list **list_a, t_list **list_b, t_utils *utils);
void	ft_update_cost_top(t_list **list_a, t_list **list_b, t_utils *utils);
void	ft_update_cost(t_list **list_a, t_list **list_b);
void	ft_push_to_bf(t_list **list_a, t_list **list_b, t_utils *utils);
int		ft_free_tab(char **s);

/*Error gestion*/
int		ft_check_sign(char *s);
int		ft_check_double(char **s);
int		ft_isnum(int c);
int		ft_check(char **s);
int		ft_is_list_sorted(t_list **list_a);

/*List Utils*/
t_list	*ft_initialisaion(int value);
void	add_elem(t_list **list, int value);
void	ft_aff_list(t_list *list); /*printf utiliser ATTENTION*/
int		list_size(t_list **list);
int		list_values(t_list **list);
void	ft_update_index(t_list **list);
void	ft_update_len(t_list **list);
void	ft_update(t_list **list, char c);
void	ft_moyenne_noed(t_list **list, int moyenne);
void	ft_init_stack_a(char **s, t_list **stack_a);
void	ft_init_stack_a(char **s, t_list **stack_a);
t_list	*ft_init(void);
int		init_b_if_null(t_list **list);
void	sort_stack(t_list **list_a);
void	insert_sorted(t_elem **sorted_head, t_elem *new_elem);
void	ft_up(t_list **stack_a, t_utils *utils);

/*algo*/
void	ft_sort_2(t_list **list_a);
void	ft_sort_3(t_list **list_a, t_utils *utils);
void	ft_sort_4(t_list **list_a, t_list **list_b, t_utils *utils);
void	ft_sort_5(t_list **list_a, t_list **list_b, t_utils *utils);
void	ft_ultimalgo(t_list **list_a, t_list **list_b, t_utils *utils);

/*Operation*/
void	swap_a(t_list **list_a);
void	swap_b(t_list **list_b);
void	swap_swap(t_list **list_a, t_list **list_b);
void	push_a(t_list **list_a, t_list **list_b, t_utils *utils);
void	push_b(t_list **list_a, t_list **list_b, t_utils *utils);
void	rotate_a(t_list **list_a);
void	rotate_b(t_list **list_b);
void	rotate_rotate(t_list **list_a, t_list **list_b);
void	reverse_ra(t_list **list_a);
void	reverse_rb(t_list **list_b);
void	rotate_rr(t_list **list_a, t_list **list_b);

#endif
