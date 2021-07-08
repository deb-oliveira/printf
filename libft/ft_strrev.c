/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:54:07 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:56:17 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char **str)
{
	size_t		len_str;
	size_t		count;
	char		temp;

	len_str = ft_strlen(*str);
	if (len_str == 0)
		return ;
	len_str--;
	count = 0;
	while (count < len_str)
	{
		temp = (*str)[count];
		(*str)[count] = (*str)[len_str];
		(*str)[len_str] = temp;
		count++;
		len_str--;
	}
}
