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

void add_elem(t_list *list, int value)
{
	t_elem *new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return ;
	new->value = value;
	new->next = list->head;
	list->head = new;
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
		printf("noed%d = %d\n", i, element->value);
		i++;
		element = element->next;
	}
	printf("\n");
}

int list_size(t_list **list)
{
	t_elem *head;
	int i;

	i = 0;
	head = (*list)->head;
	while(head->next)
	{
		i++;
		head = head->next;
	} 
	return (i);
}