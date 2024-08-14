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

int main(int ac, char **av)
{
	int i;
	char **s;
	t_list *list;


	i = 0;
	s = NULL;
	/*splitter mon tav de av et le mettre dans une stack*/
	if (ac == 2)
	{
		s = ft_split(av[1], ' ');
		while (s[i])
		{
			if (!list)
				list = ft_initialisaion(ft_atoi(s[i]));
			add_elem(list, ft_atoi(s[i]));
			printf("%s\n",s[i]);
			i++;
		}
		aff_list(list);
	}
	/*execute l'algorithme pour trier*/
	ft_algo();
	return (0);
}