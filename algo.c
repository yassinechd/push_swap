#include "push_swap.h"

void ft_sort_2(t_list **list_a)
{
	t_elem *head;

	head = (*list_a)->head;
	if (head->value > head->next->value)
		swap_a(&(*list_a));
	return ;
}

void ft_sort_3(t_list **list_a)
{
    t_elem *head;

    if (list_a == NULL || *list_a == NULL || (*list_a)->head == NULL || (*list_a)->head->next == NULL || (*list_a)->head->next->next == NULL)
        return;
    head = (*list_a)->head;
    if (head->value > head->next->value && head->next->value < head->next->next->value && head->value < head->next->next->value)
        swap_a(list_a);
    else if (head->value > head->next->value && head->next->value > head->next->next->value)
    {
        swap_a(list_a);
        reverse_ra(list_a);
    }
    else if (head->value > head->next->value && head->value > head->next->next->value && head->next->value < head->next->next->value)
        rotate_a(list_a);
    else if (head->value < head->next->value && head->next->value > head->next->next->value && head->value < head->next->next->value)
    {
        swap_a(list_a);
        rotate_a(list_a);
    }
    else if (head->value < head->next->value && head->value > head->next->next->value)
        reverse_ra(list_a);
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

void ft_push_to_bf(t_list **list_a, t_list **list_b, utils *utils)
{
    t_elem *head_b = (*list_b)->head;
    t_elem *min_cost_elem = NULL;

    while (head_b)
    {
        if (min_cost_elem == NULL || head_b->cost < min_cost_elem->cost)
            min_cost_elem = head_b;
        head_b = head_b->next;
    }
    if (min_cost_elem)
    {
        int bestfriend_index = min_cost_elem->best;
        t_elem *bestfriend = NULL;
        t_elem *head_a = (*list_a)->head;

        while (head_a)
        {
            if (head_a->index == bestfriend_index)
            {
                bestfriend = head_a;
                break;
            }
            head_a = head_a->next;
        }
        if (bestfriend)
        {
            while ((*list_a)->head != bestfriend)
                rotate_a(list_a);
            push_a(list_a, list_b, utils);
        }
    }
	ft_find_bf(list_a, list_b);
	ft_median_upt(list_a, list_b, utils);
	ft_update_cost_top(list_a, list_b, utils);
	ft_update_cost(list_a, list_b);
}

void sort_stack(t_list **list_a)
{
    if (*list_a == NULL || (*list_a)->head == NULL)
        return;

    t_elem *sorted_head = NULL;
    t_elem *current = (*list_a)->head;

    while (current != NULL)
    {
        t_elem *next = current->next;
        if (sorted_head == NULL || current->value < sorted_head->value)
        {
            current->next = sorted_head;
            sorted_head = current;
        }
        else
        {
            t_elem *sorted_current = sorted_head;
            while (sorted_current->next != NULL && sorted_current->next->value < current->value)
                sorted_current = sorted_current->next;
            current->next = sorted_current->next;
            sorted_current->next = current;
        }
        current = next;
    }
    (*list_a)->head = sorted_head;
}

void ft_ultimalgo(t_list **list_a, t_list **list_b, utils *utils)
{
    t_elem *head;

    while (utils->stacklen_a > 5) 
    {
        head = (*list_a)->head;

        if (head->moyenne == 0) 
            push_b(list_a, list_b, utils);
		else if (head->moyenne == 1)
            rotate_a(list_a);
    }
    if (utils->stacklen_a == 5)
        ft_sort_5(list_a, list_b, utils);
	ft_find_bf(list_a, list_b);
	ft_median_upt(list_a, list_b, utils);
	ft_update_cost_top(list_a, list_b, utils);
	ft_update_cost(list_a, list_b);
	while(utils->stacklen_b > 1)
		ft_push_to_bf(list_a, list_b, utils);
	ft_push_to_bf(list_a, list_b, utils);
	sort_stack(list_a);
}



