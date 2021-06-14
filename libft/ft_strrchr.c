/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 23:11:57 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/05/16 00:33:28 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	count;
	int	last;
	int	str_len;

	count = 0;
	str_len = ft_strlen((char *)str);
	if (ft_strchr(str, c) == 0)
		return (0);
	while (count < str_len + 1 && ft_strchr(str + count, c) != 0)
	{
		last = count;
		count++;
	}
	return ((char *)(str + last));
}
