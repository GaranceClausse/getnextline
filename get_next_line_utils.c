/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:52:57 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/07 17:11:58 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libc.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	if (!s1)
		return (s2);
	cpy = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		cpy[i] = s2[j];
		i++;
		j++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr(char *str, int start, int len)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!str)
		return (NULL);
	if (len <= ft_strlen(str))
		cpy = malloc(sizeof(char) * (len + 1));
	else
		cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!cpy)
		return (NULL);
	if (start > ft_strlen(str))
	{
		cpy[0] = '\0';
		return (cpy);
	}
	while (str[start] && i < len - 1)
	{
		cpy[i] = str[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	x;
	char	*str;

	i = 0;
	str = (char *)s;
	x = (char)c;
	if (c == '\0')
		return (&str[i + ft_strlen(str)]);
	while (str[i] && str[i] != x)
		i++;
	if (str[i] != '\0')
		return (&str[i]);
	else
		return (NULL);
}
