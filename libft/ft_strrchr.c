/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yass <yass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:17:12 by yachadla          #+#    #+#             */
/*   Updated: 2023/12/07 01:03:50 by yass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i])
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			last = (char *)&s[i];
			break ;
		}
		i--;
	}
	return (last);
}
