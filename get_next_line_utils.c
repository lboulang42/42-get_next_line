/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:36:50 by lboulang          #+#    #+#             */
/*   Updated: 2022/12/12 23:05:07 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < nmemb * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_join_free(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_str)
		return (NULL);
	while (str1[++i])
		new_str[i] = str1[i];
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	free(str1);
	return (new_str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
