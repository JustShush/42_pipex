/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:28:29 by dimarque          #+#    #+#             */
/*   Updated: 2023/07/14 16:56:35 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = (char *)malloc(sizeof(*s) * (len + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			tab[j] = s[i];
			j++;
		}
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

static int	ft_nstr(char const *str, char c, char **list)
{
	int	i;
	int	len;

	i = 0;
	while (*str)
	{
		len = 0;
		while (*str == c && *str)
			str++;
		if (*str)
			i++;
		while (str[len] != c && str[len])
			len++;
		if (list && i && len)
			list[i - 1] = ft_substr(str, 0, len);
		while (*str != c && *str)
			str++;
	}
	return (i);
}

char	**ft_split(char const *str, char c)
{
	char	**token;

	token = ft_calloc(sizeof(char *), (ft_nstr(str, c, NULL) + 1));
	if (!token)
		return (NULL);
	ft_nstr(str, c, token);
	return (token);
}
