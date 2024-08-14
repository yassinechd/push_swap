#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct t_elem
{
	int size;
	int 				value;
	struct t_elem		*next;
}				t_elem;

typedef struct t_list
{
	t_elem *head;
}				t_list;


/*mon atoi*/
int	ft_atoi(const char *str);


#endif