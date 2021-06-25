/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:26:36 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/25 15:37:49 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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
