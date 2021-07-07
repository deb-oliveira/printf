/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:50:28 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/06 10:57:14 by dde-oliv         ###   ########.fr       */
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

char	*ft_lutoa_base(long unsigned int nbr, char *base)
{
	unsigned int	size;
	char			*str;
	char			*str_aux;
	char			num[2];

	size = ft_strlen(base);
	if (is_base(base) == 0 || size < 2)
		return (NULL);
	str = NULL;
	if (nbr == 0)
		str = ft_strdup("0");
	num[1] = '\0';
	while (nbr != 0)
	{
		if (!str)
			str = ft_calloc(1, sizeof(char));
		str_aux = str;
		num[0] = base[nbr % size];
		str = ft_strjoin(str, num);
		free(str_aux);
		nbr = nbr / size;
	}
	ft_strrev(&str);
	return (str);
}
