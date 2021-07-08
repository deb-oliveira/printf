/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclenc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:02:42 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:55:26 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclenc(const char *str, char c1, char c2)
{
	size_t	size;

	size = 0;
	while (*str != '\0' && *str != c1)
		str++;
	while (str[size] != '\0' && str[size] != c2)
		size++;
	return (size);
}
