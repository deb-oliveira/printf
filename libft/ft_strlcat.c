/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:10:34 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/06/02 17:40:52 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	len_dest;

	count = 0;
	len_dest = ft_strlen(dest);
	if (len_dest > size)
		return (size + ft_strlen(src));
	while (count + len_dest + 1 < size && src[count] != '\0')
	{
		dest[count + len_dest] = src[count];
		count++;
	}
	dest[len_dest + count] = '\0';
	return (len_dest + ft_strlen(src));
}
