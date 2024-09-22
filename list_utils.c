#include "push_swap.h"

t_list *ft_initialisaion(int value)
{
	t_list *list;
	t_elem *elem;

	list = malloc(sizeof(t_list));
	elem = malloc(sizeof(t_elem));

	if (!elem || !list)
		return(NULL);
	elem->value = value;
	elem->next = NULL;
	list->head = elem;
	return (list);
}

void add_elem(t_list **list, int value)
{
	t_elem *new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return ;
	new->value = value;
	new->next = (*list)->head;
	(*list)->head = new;
}

void aff_list(t_list *list)
{
	if (list == NULL)
		return ;
	t_elem *noeud;
	
	noeud = list->head;

	while (noeud != NULL)
	{
		printf("%p = %d -> %p\n", noeud, noeud->value, noeud->next);
		noeud = noeud->next;
	}
	printf("NULL\n");
}

void ft_aff_list(t_list *list)
{
	int i = 0;
	t_elem *element;

	if (list == NULL)
		return ;
	element = list->head;

	while (element != NULL)
	{
		//printf("noed%d = %d  = index:%d -> moyenne : %d  best --> : %d", i, element->value, element->index, element->moyenne, element->best);
		//printf("mediane = %d, cost top = %d, cost = %d\n", element->mediane, element->cost_top, element->cost);
		printf("noed%d = %d\n",i, element->value);
		i++;
		element = element->next;
	}
	printf("\n");
}

int list_size(t_list **list)
{
    t_elem *head;
    int i;

    if (list == NULL || *list == NULL || (*list)->head == NULL)
        return 0;
    i = 0;
    head = (*list)->head;
    while (head)
    {
        head = head->next;
        i++;
    }
    return i;
}


int list_values(t_list **list)
{
	int value;

	value = 0;
	t_elem *head;

	head = (*list)->head;
	while(head)
	{
		value += head->value;
		head = head->next;
	}
	return (value);
}
void ft_init_stack_a(char **s, t_list **stack_a)
{
	int 	i;

	i = 0;
	while (s[i])
	{
		add_elem((&(*stack_a)), ft_atoi(s[i]));
		i++;
	}
}

t_list *ft_init(void)
{
	t_list *list;
	t_elem *elem;

	list = malloc(sizeof(t_list));
	elem = malloc(sizeof(t_elem));

	if (!elem || !list)
		return(NULL);
	elem = NULL;
	list->head = elem;
	return (list);
}

void ft_find_bf(t_list **list_a, t_list **list_b)
{
    int     tmp;
    t_elem  *head_a;
    t_elem  *head_b;

    head_b = (*list_b)->head;
    while (head_b)
    {
        tmp = -1;
        head_a = (*list_a)->head;
        while (head_a)
        {
            if (head_a->value > head_b->value)
            {
                if (tmp == -1 || head_a->value < (*list_a)->head->value)  
                    tmp = head_a->index;
            }
            head_a = head_a->next;
        }
        if (tmp != -1)
            head_b->best = tmp;

        head_b = head_b->next;
    }
}
void ft_median_upt(t_list **list_a, t_list **list_b, utils *utils)
{
    t_elem *head_a = (*list_a)->head;
    t_elem *head_b = (*list_b)->head;

    int median_index_a = utils->stacklen_a / 2;
    int median_index_b = utils->stacklen_b / 2;

    while (head_a)
    {
        if (head_a->index > median_index_a)
            head_a->mediane = 1;
        else
            head_a->mediane = 0;
        head_a = head_a->next;
    }
    while (head_b)
    {
        if (head_b->index >= median_index_b)
            head_b->mediane = 1;
        else
            head_b->mediane = 0;
        head_b = head_b->next;
    }
}

void ft_update_cost_top(t_list **list_a, t_list **list_b, utils *utils)
{
    t_elem *head_a;
    t_elem *head_b;

    head_a = (*list_a)->head;
    head_b = (*list_b)->head;

    while (head_a)
    {
        if (head_a->mediane == 0)
            head_a->cost_top = head_a->index;
        else if (head_a->mediane == 1)
            head_a->cost_top = utils->stacklen_a - head_a->index;
        head_a = head_a->next;
    }

    while (head_b)
    {
        if (head_b->mediane == 0)
            head_b->cost_top = head_b->index;
        else if (head_b->mediane == 1)
            head_b->cost_top = utils->stacklen_b - head_b->index;
        head_b = head_b->next;
    }
}

void ft_update_cost(t_list **list_a, t_list **list_b)
{
    t_elem *head_a;
    t_elem *head_b;
    t_elem *bestfriend;

    head_b = (*list_b)->head;
    while (head_b)
    {
        head_a = (*list_a)->head;
        bestfriend = NULL;
        while (head_a)
        {
            if (head_a->index == head_b->best)
            {
                bestfriend = head_a;
                break;
            }
            head_a = head_a->next;
        }
        if (bestfriend)
            head_b->cost = head_b->cost_top + bestfriend->cost_top;
        else
            head_b->cost = head_b->cost_top;
        head_b = head_b->next;
    }
}
