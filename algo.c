#include "push_swap.h"

void ft_sort_2(t_list **list_a)
{
	t_elem *head;

	head = (*list_a)->head;
	if (head->value > head->next->value)
		swap_a(&(*list_a));
	printf("sort 2\n");
	return ;
}

void ft_sort_3(t_list **list_a)
{
    t_elem *head;

    if (list_a == NULL || *list_a == NULL || (*list_a)->head == NULL || (*list_a)->head->next == NULL || (*list_a)->head->next->next == NULL)
    {
        printf("Erreur : Liste invalide ou trop courte pour le tri.\n");
        return;
    }
    head = (*list_a)->head;
    if (head->value > head->next->value && head->next->value < head->next->next->value && head->value < head->next->next->value)
        swap_a(list_a); // Échange les deux premiers éléments
    else if (head->value > head->next->value && head->next->value > head->next->next->value)
    {
        swap_a(list_a); // Échange les deux premiers éléments
        reverse_ra(list_a); // Déplace le plus grand élément à la fin
    }
    else if (head->value > head->next->value && head->value > head->next->next->value && head->next->value < head->next->next->value)
        rotate_a(list_a); // Déplace le plus grand élément à la fin
    else if (head->value < head->next->value && head->next->value > head->next->next->value && head->value < head->next->next->value)
    {
        swap_a(list_a); // Échange les deux premiers éléments
        rotate_a(list_a); // Déplace le plus grand élément à la fin
    }
    else if (head->value < head->next->value && head->value > head->next->next->value)
        reverse_ra(list_a); // Déplace le plus grand élément à la fin
    return;
}

void ft_sort_4(t_list **list_a, t_list **list_b, utils *utils)
{
	int min;

	min = ft_min(&(*list_a));
	if (min == 0)
	{
		push_b(&(*list_a), &(*list_b), utils);
		if(ft_is_list_sorted(&(*list_a)) == 1)
			return ;
		ft_sort_3(&(*list_a));
		push_a(&(*list_a), &(*list_b), utils);
	}
	else if (min == 1)
	{
		swap_a(&(*list_a));
		if(ft_is_list_sorted(&(*list_a)) == 1)
			return ;
		push_b(&(*list_a), &(*list_b), utils);
		ft_sort_3(&(*list_a));
		push_a(&(*list_a), &(*list_b), utils);
	}
	else if (min == 2)
	{
		reverse_ra(&(*list_a));
		reverse_ra(&(*list_a));
		if(ft_is_list_sorted(&(*list_a)) == 1)
			return ;
		push_b(&(*list_a), &(*list_b), utils);
		ft_sort_3(&(*list_a));
		push_a(&(*list_a), &(*list_b), utils);
	}
	else if (min == 3)
	{
		reverse_ra(&(*list_a));
		if(ft_is_list_sorted(&(*list_a)) == 1)
			return ;
		push_b(&(*list_a), &(*list_b), utils);
		ft_sort_3(&(*list_a));
		push_a(&(*list_a), &(*list_b), utils);
	}
}

void ft_sort_5(t_list **list_a, t_list **list_b, utils *utils)
{
	int min;

	min = ft_min(&(*list_a));
	if (min == 0)
		push_b(&(*list_a), &(*list_b), utils);
	else if (min == 1)
	{
		swap_a(&(*list_a));
		push_b(&(*list_a), &(*list_b), utils);
	}
	else if (min == 2)
	{
		rotate_a(&(*list_a));
		rotate_a(&(*list_a));
		push_b(&(*list_a), &(*list_b), utils);
	}
	else if (min == 3)
	{
		reverse_ra(&(*list_a));
		reverse_ra(&(*list_a));
		push_b(&(*list_a), &(*list_b), utils);

	}
	else if (min == 4)
	{
		reverse_ra(&(*list_a));
		push_b(&(*list_a), &(*list_b), utils);
	}
	ft_sort_4(&(*list_a), &(*list_b), utils);
	push_a(&(*list_a), &(*list_b), utils);
}

void ft_ultimalgo(t_list **list_a, t_list **list_b, utils *utils)
{
    t_elem *head;

	head = (*list_a)->head;

    printf("algo ultime\n");
    printf("taille : %d\n", utils->stacklen_a); // Affichage de la taille initiale

    // Recommencer la vérification depuis le début de la liste après chaque opération
    while (head && utils->stacklen_a > 5) // Initialiser head au début de chaque boucle
    {
		
		printf("stack len a : %d\n", utils->stacklen_a);
        if (head->moyenne == 0)
            push_b(list_a, list_b, utils);
        if (head->moyenne == 1)
            rotate_a(list_a);
		head = (*list_a)->head;
		head = head->next;
        // Pas besoin de faire `head = head->next;` car la boucle recommence avec le nouveau head.
    }
	if (utils->stacklen_a == 5)
	{
		ft_sort_5(list_a, list_b, utils);
	}
}


