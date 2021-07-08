/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:26:36 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:56:45 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strxlen(char *src, char x)
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
