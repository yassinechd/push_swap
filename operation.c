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
}

/*faire securiter pour les swap si il n'y en as que 1*/
void swap_swap(t_list **list_a, t_list **list_b)
{
    swap_a(list_a);
    swap_b(list_b);
}

void push_a(t_list **list_a, t_list **list_b)
{
	if (*list_b == NULL || (*list_b)->head == NULL)
        return;
	t_elem *top_b;

	top_b = (*list_b)->head;
	(*list_b)->head = top_b->next;
	top_b->next = (*list_a)->head;
	(*list_a)->head = top_b;
}
void push_b(t_list **list_a, t_list **list_b)
{
	if (*list_a == NULL || (*list_a)->head == NULL)
        return;
	t_elem *top_a;

	top_a = (*list_a)->head;
	(*list_a)->head = top_a->next;
	top_a->next = (*list_b)->head;
	(*list_b)->head = top_a;
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
}
void rotate_rr(t_list **list_a, t_list **list_b)
{
    reverse_ra(list_a);
    reverse_rb(list_b);
}
