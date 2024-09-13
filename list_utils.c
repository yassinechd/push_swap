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
		printf("noed%d = %d  = index:%d -> moyenne : %d\n", i, element->value, element->index, element->moyenne);
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
        return 0; // Retourner 0 si la liste est nulle ou vide

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


//list_t *ft_creat_elem(void *data)
//{
//	list_t *new;

//	new = malloc(sizeof(list_t));
//	if (!new)
//		return (NULL);
//	new->data = data;
//	new->next = NULL;
//	return (new);
//} 

//void ft_list_push_front(list_t **head, void *data)
//{
//	list_t *new_head;
//	list_t *old_head;

//	old_head = (*head);
//	new_head = ft_creat_elem(data);
//	if (!new_head)
//		return ;
//	new_head->next = old_head;
//	(*head) = new_head;
//}

//int ft_list_size(list_t *begin_list)
//{
//	int i;

//	i = 0;	
//	while(begin_list)
//	{
//		begin_list = begin_list->next;
//		i++;
//	}	
//	return (i);
//}
//list_t *ft_list_last(list_t *begin_list)
//{
//	if (!begin_list)
//		return (NULL);
//	while (begin_list)
//		begin_list = begin_list->next;
//	return (begin_list);
//}
//void ft_list_push_back(list_t **begin_list, void *data)
//{
//	list_t *head;
//	list_t *new_elem;

//	new_elem = ft_creat_elem(data);
//	if (!new_elem)
//		return ;
//	if (!(*begin_list))
//	{
//		*begin_list = new_elem;
//		return;
//	}
//	head = (*begin_list);
//	while (head)
//		head = head->next;
//	head->next = ft_creat_elem(data);
//}
