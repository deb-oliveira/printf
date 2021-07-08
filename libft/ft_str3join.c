/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:41:18 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:54:46 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	int		len_str;
	int		i;
	int		j;
	int		k;

	len_str = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	i = 1;
	while (i++ && s1[i - 2] != '\0')
		str[i - 2] = s1[i - 2];
	j = 1;
	while (j++ && s2[j - 2] != '\0')
		str[i + j - 4] = s2[j - 2];
	k = 1;
	while (k++ && s3[k - 2] != '\0')
		str[i + j + k - 6] = s3[k - 2];
	str[i + j + k - 6] = '\0';
	return (str);
}
