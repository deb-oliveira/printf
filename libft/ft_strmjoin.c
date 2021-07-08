/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:34:39 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:56:02 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmjoin(char const *s1, char const *s2, int start)
{
	char	*str;
	char	*s1_aux;
	char	*str_aux;

	s1_aux = ft_substr(s1, 0, start);
	str = ft_strjoin(s1_aux, s2);
	free(s1_aux);
	str_aux = str;
	str = ft_strjoin(str, s1 + start);
	free(str_aux);
	return (str);
}
