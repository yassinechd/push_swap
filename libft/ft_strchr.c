/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:58 by yass              #+#    #+#             */
/*   Updated: 2023/11/27 20:32:02 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int					i;
	unsigned char		ca;
	char				*str;

	ca = (unsigned char)c;
	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == ca)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == ca)
		return ((char *)&str[i]);
	return (NULL);
}
