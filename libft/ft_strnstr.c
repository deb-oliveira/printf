/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:34:45 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/05/19 17:04:46 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	to_find_size;

	to_find_size = ft_strlen((char *)to_find);
	if (to_find_size == 0)
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (to_find[j] == str[i + j] && i + j < len)
		{
			if (j == to_find_size - 1)
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (0);
}
