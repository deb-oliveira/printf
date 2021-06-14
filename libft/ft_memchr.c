/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:43:13 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/05/17 21:16:38 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && *((unsigned char *)str + count) != (unsigned char) c)
		count++;
	if (count == n)
		return (0);
	else
		return ((unsigned char *)(str + count));
}
