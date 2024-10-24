/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:03:13 by yass              #+#    #+#             */
/*   Updated: 2023/12/18 23:01:56 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab;
	unsigned int	i;
	unsigned int	j;

	if (!s || !f)
		return (NULL);
	j = (unsigned int)ft_strlen(s);
	tab = (char *)malloc(sizeof(char) * (j + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < j)
	{
		tab[i] = (*f)(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
