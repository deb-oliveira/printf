/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:30:13 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 09:01:25 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memjoin(const char *s1, const char *s2, size_t size1, size_t size2)
{
	char			*str;
	size_t			len_str;
	size_t			i;
	size_t			j;

	if (!s1 || !s2)
		return (NULL);
	len_str = size1 + size2;
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (i + j < len_str)
	{
		str[i + j] = s2[j];
		j++;
	}	
	str[i + j] = '\0';
	return (str);
}
