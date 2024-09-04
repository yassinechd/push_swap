#include "push_swap.h"

void swap_a(t_list **list)
{
	t_elem *top;
	t_elem *next;

	top = (*list)->head;
	next = top->next;
	
	top->next = next->next;
	next->next = top;
	(*list)->head = next;
}

int main(int ac, char **av) 
{
	int i;
	char	**s;
	t_list	*stack_a;
	t_list	*stack_b;


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
			printf("%s\n",s[i]);
			i++;
		}
		printf("---------------------------\n");
		ft_aff_list(stack_a);
		/*algo*/
		algo(&stack_a, &stack_b);
		ft_aff_list(stack_a);
	return (0);
}