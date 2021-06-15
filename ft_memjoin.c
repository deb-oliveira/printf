/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:30:13 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/15 09:47:36 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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
