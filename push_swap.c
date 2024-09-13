#include "push_swap.h"

//void swap_a(t_list **list)
//{
//	t_elem *top;
//	t_elem *next;

//	top = (*list)->head;
//	next = top->next;
	
//	top->next = next->next;
//	next->next = top;
//	(*list)->head = next;
//}

list_t *ft_creat_elem(void *data)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
} 

void ft_list_push_front(list_t **head, void *data)
{
	list_t *new_head;
	list_t *old_head;

	old_head = (*head);
	new_head = ft_creat_elem(data);
	if (!new_head)
		return ;
	new_head->next = old_head;
	(*head) = new_head;
}

int ft_list_size(list_t *begin_list)
{
	int i;

	i = 0;	
	while(begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}	
	return (i);
}
list_t *ft_list_last(list_t *begin_list)
{
	if (!begin_list)
		return (NULL);
	while (begin_list)
		begin_list = begin_list->next;
	return (begin_list);
}
void ft_list_push_back(list_t **begin_list, void *data)
{
	list_t *head;
	list_t *new_elem;

	new_elem = ft_creat_elem(data);
	if (!new_elem)
		return ;
	if (!(*begin_list))
	{
		*begin_list = new_elem;
		return;
	}
	head = (*begin_list);
	while (head)
		head = head->next;
	head->next = ft_creat_elem(data);
}
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

	head = (*list_a)->head;
	if(head->value < head->next->value && head->value > head->next->next->value)
		reverse_ra(&(*list_a));
	if (head->next->next->value < head->next->value)
	{
		reverse_ra(&(*list_a));
		ft_sort_2(&(*list_a));
	}
	printf("sort 3\n");
	return ;
}

void ft_sort_4(t_list **list_a)
{
    t_elem *head_a;

    head_a = (*list_a)->head;
}

int ft_is_list_sorted(t_list **list_a)
{
    t_elem *head;

    // Vérifier si la liste est vide
    if (!list_a || !(*list_a) || !(*list_a)->head)
        return (1); // Considérer une liste vide comme triée

    head = (*list_a)->head;
    while (head && head->next) // Assurez-vous que head->next n'est pas NULL
    {
        if (head->value > head->next->value)
        {
            printf("not sorted\n");
            return (0);
        }
        head = head->next;
    }
    printf("sorted\n");
    return (1);
}

//void ft_sort_2(t_list **list_a, t_list **list_b)
//{
//	t_elem *head;

//	head = (*list_a)->head;
//	if (head->value < head->next->value)
//		swap_a(&list_a);
//	return ;
//}

t_list *ft_initialisaion_b(void)
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

int main(int ac, char **av) 
{
	int i;
	char	**s;
	t_list	*stack_a;
	t_list	*stack_b;
	utils	utils;


	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	s = NULL;
	if (ac == 0 || av[0] == NULL || av[1] == NULL)
		return (1);
	if (ac == 2)
		s = ft_split(av[1], ' ');
	if (ac > 2)
		s = av + 1;
	if (ft_check(s) == 0)
	{
		/*erreur de param*/
		printf("Erreur Parametre\n");
		return (0);
	}
	while (s[i])
	{
		if (!stack_a)
			stack_a = ft_initialisaion(ft_atoi(s[i]));
		else
			add_elem(stack_a, ft_atoi(s[i]));
		//printf("%s\n",s[i]);
		i++;
	}
	ft_aff_list(stack_a);
	if (ft_is_list_sorted(&stack_a) == 1)
		exit(0) ;
	stack_b = ft_initialisaion_b();
	utils.stacklen_a = list_size(&stack_a);
	utils.moyenne = utils.stacklen_a / list_values(&stack_a);
	printf("%d\n", utils.stacklen_a);
	if (utils.stacklen_a == 2)
		ft_sort_2(&stack_a);
	if (utils.stacklen_a == 3)
		ft_sort_3(&stack_a);
	if (utils.stacklen_a == 4)
		ft_sort_4(&stack_a);

	printf("---------------------------\n");
	ft_aff_list(stack_a);
	ft_aff_list(stack_b);
	return (0);
}
