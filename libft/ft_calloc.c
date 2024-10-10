/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:06 by yass              #+#    #+#             */
/*   Updated: 2023/11/30 19:52:56 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t size)
{
	unsigned char	*tab;

	tab = (unsigned char *)malloc(size * nelem);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (nelem * size));
	return ((void *)tab);
}
