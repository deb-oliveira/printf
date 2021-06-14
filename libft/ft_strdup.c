/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:25:05 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/05/17 16:36:41 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*src_copy;
	int		count;

	src_copy = malloc(ft_strlen(src) + 1);
	if (!src_copy)
		return (NULL);
	count = 0;
	while (src[count] != '\0')
	{
		src_copy[count] = src[count];
		count++;
	}
	src_copy[count] = '\0';
	return (src_copy);
}
