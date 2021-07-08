/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:53:06 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:52:00 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_llitoa_base(long long int nbr, char *base)
{
	int				size;
	char			*str;
	char			*str_aux;

	if (nbr >= 0)
		return (ft_llutoa_base((long long unsigned int)nbr, base));
	size = ft_strlen(base);
	str = ft_strdup("-");
	while (nbr != 0)
	{
		str_aux = str;
		str = ft_strcjoin(str, base[-(nbr % -size)]);
		free(str_aux);
		nbr = nbr / size;
	}
	str++;
	ft_strrev(&str);
	str--;
	return (str);
}
