/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:03:02 by yass              #+#    #+#             */
/*   Updated: 2023/12/18 23:02:25 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	j;

	i = 0;
	if (!f || !s)
		return ;
	j = (int)ft_strlen(s);
	if (s != NULL && f != NULL)
	{
		while (i < j && s != NULL && f != NULL)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
