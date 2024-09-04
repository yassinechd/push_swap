#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

/*def element de list chainée*/
typedef struct t_elem
{
	int					size;
	int 				value;
	struct t_elem		*next;
}						t_elem;

/*tete de la liste chainée*/
typedef struct t_list
{
	t_elem 				*head;
}						t_list;


/*Utils*/
int	ft_atoi(const char *str);

/*Error gestion*/
int ft_check_sign(char *s);
int	ft_check_double(char **s);
int	ft_isnum(int c);
int ft_check(char **s);

/*List Utils*/
t_list *ft_initialisaion(int value);
void add_elem(t_list *list, int value);
void ft_aff_list(t_list *list); /*printf utiliser ATTENTION*/
int list_size(t_list **list);

/*Operation*/
void swap_a(t_list **list_a);
void swap_b(t_list **list_b);
void swap_swap(t_list **list_a, t_list **list_b);
void push_a(t_list **list_a, t_list **list_b);
void push_b(t_list **list_a, t_list **list_b);
void rotate_a(t_list **list_a);
void rotate_b(t_list **list_b);
void rotate_rotate(t_list **list_a, t_list **list_b);
void reverse_ra(t_list **list_a);
void reverse_rb(t_list **list_b);
void rotate_rr(t_list **list_a, t_list **list_b);

#endif
