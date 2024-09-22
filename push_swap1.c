#include "push_swap.h"


void ft_update(t_list **list, char c)
{
	utils utils;

	if (c == 'a')
	{
		utils.stacklen_a = list_size(&(*list));
		utils.moyenne = list_values(&(*list)) / utils.stacklen_a;
	}
	if (c == 'b')
		utils.stacklen_b = list_size(&(*list));
	ft_update_index(&(*list));
	ft_moyenne_noed(&(*list), utils.moyenne);
}

//void ft_utils_init(void)
//{
//	utils utils;

//	utils.moyenne = 0;
//	utils.stacklen_a = 0;
//	utils.stacklen_b = 0;
//}
int main(int ac, char **av) 
{
	char	**s;
	t_list	*stack_a;
	t_list	*stack_b;
	utils	utils;

	//ft_utils_init();
	/*initialisation des deux stack avec un elem NULL dedans*/
	s = NULL;
	stack_a = ft_init();
	stack_b = ft_init();

	/*check si les param sont bon et si les argument sont bon*/
	if (ac == 0 || av[0] == NULL || av[1] == NULL)
		exit(0) ;
	if (ac == 2)
		s = ft_split(av[1], ' ');
	if (ac > 2)
		s = av + 1;
	if (ft_check(s) == 0)
		exit(0) ;

	/*remplir la stack A avec value et mise a jour de l'index de chacun des noeud*/
	ft_init_stack_a(s, &stack_a);
	ft_update_index(&stack_a);

	/*check si la liste est deja trier*/
	if (ft_is_list_sorted(&stack_a) == 1)
		exit(0);
	utils.stacklen_a = list_size(&stack_a);
	utils.moyenne = list_values(&stack_a) / utils.stacklen_a;
	ft_moyenne_noed(&stack_a, utils.moyenne);
	
	ft_aff_list(stack_a);
	if (utils.stacklen_a == 2)
		ft_sort_2(&stack_a);
	if (utils.stacklen_a == 3)
		ft_sort_3(&stack_a);
	if (utils.stacklen_a == 4)
		ft_sort_4(&stack_a, &stack_b, &utils);
	if (utils.stacklen_a == 5)
		ft_sort_5(&stack_a, &stack_b, &utils);
	printf("%d\n", utils.stacklen_a);
	if (utils.stacklen_a > 5)
		ft_ultimalgo(&stack_a, &stack_b, &utils);  // Passe l'adresse de utils
	ft_aff_list(stack_a);
	printf("stack len a : %d\n", utils.stacklen_a);
	printf("-------------\n");
	ft_aff_list(stack_b);
}