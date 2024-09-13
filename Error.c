#include "push_swap.h"


int	ft_isnum(int c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_check_double(char **s)
{
	int i;
	int j;
	int vue;

	i = 0;

	while (s[i])
	{
		vue = ft_atoi(s[i]);
		j = i + 1;
		while(s[j])
		{
			if (ft_atoi(s[j]) == vue)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*check si j'ai des lettre dns mon input*/
int ft_check_sign(char *s)
{
	int i;
	int signe;

	signe = 0;
	i = 0;
	while(s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			signe++;
		if (signe == 2)
			return (0);
		i++;
	}
	return (1);
}

int ft_check(char **s)
{
	int i;
	int j;
	int signe_db;

	signe_db = 0;
	i = 0;
	while(s[i])
	{
		j = 0;
		while(s[i][j])
		{
			/*si il trouve autre chose qu'un num ou des signe renvoi une erreur*/
			if (ft_isnum(s[i][j]) == 0)
			{
				printf("ERROR PRAM");
				return (0);
			}
			j++;
		}
		if (ft_check_sign(s[i]) == 0)
		{
			printf("ERROR PRAM");
			return (0);
		}
		//printf("%d\n", i);
		i++;
	}
	if (ft_check_double(s) == 0)
	{
		printf("ERROR PRAM");
		return (0);
	}
	ft_check_double(s);
	return (1);
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