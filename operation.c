#include "push_swap.h"

void swap_a(t_list **list_a)
{
	if (*list_a == NULL || (*list_a)->head == NULL || (*list_a)->head->next == NULL)
        return;
	t_elem *top;
	t_elem *next;

	top = (*list_a)->head;
	next = top->next;

	top->next = next->next;
	next->next = top;
	(*list_a)->head = next;
	ft_update_index(&(*list_a));
	printf("sa\n");
}

void swap_b(t_list **list_b)
{
	if (*list_b == NULL || (*list_b)->head == NULL || (*list_b)->head->next == NULL)
        return;
	t_elem *top;
	t_elem *next;

	top = (*list_b)->head;
	next = top->next;
	
	top->next = next->next;
	next->next = top;
	(*list_b)->head = next;
	ft_update_index(&(*list_b));
	printf("sb\n");
}

/*faire securiter pour les swap si il n'y en as que 1*/
void swap_swap(t_list **list_a, t_list **list_b)
{
    swap_a(list_a);
    swap_b(list_b);
}
/*corriger push_a et push_b pour le cas si list_b ou list_a est vide*/
void push_a(t_list **list_a, t_list **list_b, utils *utils)
{

	if (*list_b == NULL || (*list_b)->head == NULL)
        return;
	t_elem *top_b;

	top_b = (*list_b)->head;
	(*list_b)->head = top_b->next;
	top_b->next = (*list_a)->head;
	(*list_a)->head = top_b;

	utils->stacklen_a = list_size(&(*list_a));
	utils->moyenne = list_values(&(*list_a)) / utils->stacklen_a;
	ft_update_index(&(*list_a));
	ft_moyenne_noed(&(*list_a), utils->moyenne);

	utils->stacklen_b = list_size(&(*list_b));
	utils->moyenne = list_values(&(*list_b)) / utils->stacklen_b;
	ft_update_index(&(*list_b));
	ft_moyenne_noed(&(*list_b), utils->moyenne);
	printf("pa -- %d  %d\n", utils->stacklen_a, utils->stacklen_b);
}
void push_b(t_list **list_a, t_list **list_b, utils *utils)
{
	if (*list_a == NULL || (*list_a)->head == NULL)
        return;
	t_elem *top_a;
	/*correction temporaire pour cree une stack_b si celle ci est vide*/
	if (*list_b == NULL)
    {
        *list_b = malloc(sizeof(t_list));
        if (*list_b == NULL)
            return;
        (*list_b)->head = NULL;
    }
	top_a = (*list_a)->head;
	(*list_a)->head = top_a->next;
	top_a->next = (*list_b)->head;
	(*list_b)->head = top_a;
	utils->stacklen_a = list_size(&(*list_a));
	utils->moyenne = list_values(&(*list_a)) / utils->stacklen_a;
	ft_update_index(&(*list_a));
	ft_moyenne_noed(&(*list_a), utils->moyenne);
	
	utils->stacklen_b = list_size(&(*list_b));
	utils->moyenne = list_values(&(*list_b)) / utils->stacklen_b;
	ft_update_index(&(*list_b));
	ft_moyenne_noed(&(*list_b), utils->moyenne);
	printf("pb\n");
}
void rotate_a(t_list **list_a)
{
    if (*list_a == NULL || (*list_a)->head == NULL || (*list_a)->head->next == NULL)
        return; 
    t_elem *top;
    t_elem *last;

    top = (*list_a)->head; 
    last = (*list_a)->head;

    while (last->next != NULL)
    {
        last = last->next;
    }
    (*list_a)->head = top->next;
    last->next = top;
    top->next = NULL;
	ft_update_index(&(*list_a));
	printf("ra\n");
}

void rotate_b(t_list **list_b)
{
    if (*list_b == NULL || (*list_b)->head == NULL || (*list_b)->head->next == NULL)
        return; 
    t_elem *top;
    t_elem *last;

    top = (*list_b)->head; 
    last = (*list_b)->head;

    while (last->next != NULL)
    {
        last = last->next;
    }
    (*list_b)->head = top->next;
    last->next = top;
    top->next = NULL;
	ft_update_index(&(*list_b));
	printf("rb\n");
}

void rotate_rotate(t_list **list_a, t_list **list_b)
{
    rotate_a(list_a);
    rotate_b(list_b);
}

void reverse_ra(t_list **list_a)
{
    if (*list_a == NULL || (*list_a)->head == NULL || (*list_a)->head->next == NULL)
        return;
    t_elem *top;
    t_elem *prev;
    t_elem *bot;

    top = (*list_a)->head;
    bot = (*list_a)->head; 
    prev = NULL;

    while (bot->next != NULL)
    {
        prev = bot;
        bot = bot->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    bot->next = top;
    (*list_a)->head = bot;
	ft_update(&(*list_a), 'a');
	printf("rra\n");
}
void reverse_rb(t_list **list_b)
{
    if (*list_b == NULL || (*list_b)->head == NULL || (*list_b)->head->next == NULL)
        return;
    t_elem *top;
    t_elem *prev;
    t_elem *bot;

    top = (*list_b)->head;
    bot = (*list_b)->head; 
    prev = NULL;

    while (bot->next != NULL)
    {
        prev = bot;
        bot = bot->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    bot->next = top;
    (*list_b)->head = bot;
	ft_update(&(*list_b), 'b');
	printf("rrb\n");
}
void rotate_rr(t_list **list_a, t_list **list_b)
{
    reverse_ra(list_a);
    reverse_rb(list_b);
}
