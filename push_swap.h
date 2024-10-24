/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:17:12 by yachadla          #+#    #+#             */
/*   Updated: 2024/10/06 22:38:16 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libftprintf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_elem
{
	int				cost_to_bf;
	int				cost_to_top;
	int				mediane;
	int				bestfriend;
	int				moyenne;
	int				index;
	int				value;
	struct s_elem	*next;
}					t_elem;

typedef struct t_list
{
	int				cost_alg;
	int				index_alg;
	int				mediane_alg;
	int				bestfriend_alg;
	int				mediane_of_min2;
	int				min;
	int				mediane_of_min;
	int				f;
	int				s;
	int				t;
	int				mediane_a;
	int				mediane_b;
	int				stacklen_a;
	int				stacklen_b;
	int				moyenne;
	t_elem			*head_a;
	t_elem			*head_b;
}					t_list;

// error check
int					ft_check(char **s);
int					ft_check_sign(char *s);
int					ft_check_double(char **s);
int					ft_isnum(int c);

// update
void				ft_update_len_and_index(t_list **list);
int					calc_mediane(int stacklen);
void				ft_mediane_noed(t_list **list);
void				ft_update_moyenne(t_list **list);
void				ft_the_big_up(t_list **list);
void				ft_find_bf(t_list **list);

// operation
void				swap_a(t_list **list);
void				swap_b(t_list **list);
void				push_b(t_list **list);
void				push_a(t_list **list);
void				rotate_a(t_list **list, int i);
void				rotate_b(t_list **list, int i);
void				reverse_ra(t_list **list, int i);
void				reverse_rb(t_list **list, int i);
void				rr(t_list **list);
void				rrr(t_list **list);

// algo
void				ft_sort_2(t_list **list);
void				ft_sort_3(t_list **list);
void				ft_sort_4(t_list **list);
void				ft_sort_5(t_list **list);
void				ft_ultimalgo(t_list **list);

// listes utils
void				ft_aff_list(t_list *list);
t_list				*ft_init_listes(void);
int					list_values(t_list **list);
void				add_elem(t_list **list, int value);
void				ft_fill_stack(char **s, t_list **listes);
void				ft_update_cost(t_list **list);
void				ft_update_cost_top(t_list **list);
void				ft_sort_stack(t_list **list);

// utils
void				ft_min(t_list **list);
int					ft_is_list_sorted(t_list **list);
void				ft_mediane_w_index(t_list **list);
int					ft_up_the_bf(t_list **list, int bestfriend);
void				ft_rotate_to_bestfriend(t_list **list, int *index_bf,
						int *mediane);
int					ft_find_bestfriend(t_list **list, int bestfriend,
						int *index_bf, int *mediane);
void				ft_find_min_cost(t_list **list);
int					ft_up_the_bf(t_list **list, int bestfriend);
int					ft_min_cost(t_list **list);
void				ft_push_to_bf(t_list **list);
void				ft_min(t_list **list);

#endif
