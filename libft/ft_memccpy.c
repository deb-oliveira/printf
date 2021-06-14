/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:44:06 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/05/21 11:08:55 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && ((unsigned char *)src)[count] != (unsigned char)c)
	{
		((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
		count++;
	}
	if (count == n)
		return (NULL);
	((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
	return (dest + count + 1);
}
