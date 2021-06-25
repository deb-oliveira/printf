/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:59:12 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/25 11:52:00 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static size_t	ft_strxlen(char *src, char x)
{
	size_t	size;
	size_t	count;

	count = 0;
	size = 0;
	while (src[count] != '\0')
	{
		if (src[count] != x)
			size++;
		count++;
	}
	return (size);
}

char	*ft_strxdup(char *src, char x)
{
	char	*src_copy;
	int		size;
	int		count;

	src_copy = malloc(ft_strxlen(src, x) + 1);
	if (!src_copy)
		return (NULL);
	count = 0;
	size = 0;
	while (src[count] != '\0')
	{
		if (src[count] != x)
		{
			src_copy[size] = src[count];
			size++;
		}
		count++;
	}
	src_copy[size] = '\0';
	return (src_copy);
}
