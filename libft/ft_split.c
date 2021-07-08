/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 00:30:16 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 16:36:01 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_build_words(int j, char **split, char *scpy, char c)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		if (i != j)
		{
			split[i] = ft_substr(scpy, 0, ft_strchr(scpy, c) - scpy);
			scpy = ft_strchr(scpy, c);
			while (*scpy == c)
				scpy++;
		}
		else if (*scpy != '\0')
			split[i] = ft_strdup(scpy);
		i++;
	}
	if (*scpy == '\0' && j == 0)
		split[j] = NULL;
	else
		split[j + 1] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	*scpy;
	char	*scpy2;
	char	**split;

	if (!s)
		return (NULL);
	scpy = ft_strtrim(s, &c);
	if (!scpy)
		return (NULL);
	scpy2 = scpy;
	i = 0;
	j = 0;
	while (scpy[i] != '\0' && ft_strchr(scpy + i, c) != NULL)
	{
		if (i > 0 && scpy[i - 1] != c && scpy[i] == c)
			j++;
		i++;
	}
	split = malloc(sizeof(char *) * (j + 2));
	if (split)
		ft_build_words(j, split, scpy, c);
	free(scpy2);
	return (split);
}
