/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpointtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:48:34 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/24 14:16:08 by doliveira        ###   ########.fr       */
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

static void	get_round(char **str, size_t str_len)
{
	char	*str_aux;

	str_aux = *str;
	*str = ft_strcjoin(*str, '0');
	free(str_aux);
	while (str_len > 0 && *str[str_len - 1] == '9')
	{
		*str[str_len - 1] = '0';
		str_len--;
	}
	if (str_len == 0)
	{
		str_aux = *str;
		*str = ft_strjoin("1.", *str);
		free(str_aux);
	}
	else
		*str[str_len - 1] = *str[str_len - 1] + 1;
}

static void	get_lastdigit(double nbr, char *base, size_t base_size, char **str)
{
	char	ldigit;
	char	*str_aux;
	size_t	str_len;

	str_len = ft_strlen(*str);
	ldigit = base[(int)(nbr * 10) % base_size];
	nbr = nbr * 10 - (int)(nbr * 10.0);
	if (base[(int)(nbr * 10) % base_size] - 48 <= 5
		|| (ldigit - 48) % 2 == 0 || ldigit != '9')
	{
		str_aux = *str;
		if (base[(int)(nbr * 10) % base_size] - 48 <= 5)
			*str = ft_strcjoin(*str, ldigit);
		else
			*str = ft_strcjoin(*str, ldigit + 1);
		free(str_aux);
	}
	else
		get_round(str, str_len);
}

char	*ft_dpointtoa_base(double nbr, char *base, size_t precision)
{
	size_t			size;
	char			*str;
	char			*str_aux;
	size_t			count;

	size = ft_strlen(base);
	if (is_base(base) == 0 || size < 2)
		return (NULL);
	if (nbr == 0)
	{
		str = ft_strcjoin("", base[0]);
		return (str);
	}
	if (precision == 0)
	{
		if (base[(int)(nbr * 10) % size] < '5')
			str = ft_strdup("0");
		else
			str = ft_strdup("1.0");
		return (str);
	}
	str = ft_calloc(1, sizeof(char));
	count = 0;
	while (nbr != 0 && count + 1 < precision)
	{
		str_aux = str;
		str = ft_strcjoin(str, base[(int)(nbr * 10) % size]);
		free(str_aux);
		nbr = nbr * 10 - (int)(nbr * 10.0);
		count++;
	}
	get_lastdigit(nbr, base, size, &str);
	return (str);
}
