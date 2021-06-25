/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u128toa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:30:07 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/23 16:08:11 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static unsigned int	is_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_u128toa_base(__uint128_t nbr, char *base)
{
	unsigned int	size;
	char			*str;
	char			*str_aux;

	size = ft_strlen(base);
	if (is_base(base) == 0 || size < 2)
		return (NULL);
	if (nbr == 0)
	{
		str = ft_strcjoin("", base[0]);
		return (str);
	}
	str = ft_calloc(1, sizeof(char));
	while (nbr != 0)
	{			
		str_aux = str;
		str = ft_strcjoin(str, base[nbr % size]);
		free(str_aux);
		nbr = nbr / size;
	}
	str = ft_strrev(str);
	return (str);
}
