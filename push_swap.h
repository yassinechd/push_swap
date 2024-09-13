#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

/*def element de list chainée*/
typedef struct t_elem
{
	int					moyenne;
	int					index;
	int 				value;
	struct t_elem		*next;
}						t_elem;

/*tete de la liste chainée*/
typedef struct t_list
{
	t_elem 				*head;
}						t_list;

typedef struct list_t
{
	struct list_t		*next;
	void				*data;			
}						list_t;

typedef struct	t_utils
{
	int			moyenne;
	int			stacklen_a;
	int			stacklen_b;
}				utils;

/*Utils*/
int	ft_atoi(const char *str);
void ft_moyenne_noed(t_list **list, int moyenne);
int ft_min(t_list **list);
void ft_update_index(t_list **list);

/*Error gestion*/
int ft_check_sign(char *s);
int	ft_check_double(char **s);
int	ft_isnum(int c);
int ft_check(char **s);
int ft_is_list_sorted(t_list **list_a);

/*List Utils*/
t_list *ft_initialisaion(int value);
void add_elem(t_list **list, int value);
void ft_aff_list(t_list *list); /*printf utiliser ATTENTION*/
int list_size(t_list **list);
int list_values(t_list **list);
void ft_update_index(t_list **list);
void ft_update_len(t_list **list);
void ft_update(t_list **list, char c);
void ft_moyenne_noed(t_list **list, int moyenne);
void ft_init_stack_a(char **s, t_list **stack_a);
void ft_init_stack_a(char **s, t_list **stack_a);
t_list *ft_init(void);
 
/*algo*/
void ft_sort_2(t_list **list_a);
void ft_sort_3(t_list **list_a);
void ft_sort_4(t_list **list_a, t_list **list_b, utils *utils);
void ft_sort_5(t_list **list_a, t_list **list_b, utils *utils);
void ft_ultimalgo(t_list **list_a, t_list **list_b, utils *utils);

/*Operation*/
void swap_a(t_list **list_a);
void swap_b(t_list **list_b);
void swap_swap(t_list **list_a, t_list **list_b);
void push_a(t_list **list_a, t_list **list_b, utils *utils);
void push_b(t_list **list_a, t_list **list_b, utils *utils);
void rotate_a(t_list **list_a);
void rotate_b(t_list **list_b);
void rotate_rotate(t_list **list_a, t_list **list_b);
void reverse_ra(t_list **list_a);
void reverse_rb(t_list **list_b);
void rotate_rr(t_list **list_a, t_list **list_b);

#endif
