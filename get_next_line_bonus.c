/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:12 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/09 16:58:34 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <libc.h>

static char	*get_one_line(char *cpy)
{
	int		i;
	char	*s2;

	i = 0;
	if (!cpy[i])
		return (NULL);
	while (cpy[i] && cpy[i] != '\n')
		i++;
	s2 = malloc(sizeof(char) * (i + 2));
	if (!s2)
		return (NULL);
	i = 0;
	while (cpy[i] && cpy[i] != '\n')
	{
		s2[i] = cpy[i];
		i++;
	}
	if (cpy[i] == '\n')
	{
		s2[i] = '\n';
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static char	*save_cpy(char *cpy)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (cpy[i] && cpy[i] != '\n')
		i++;
	if ((cpy[i] == '\n' && cpy[i + 1] == '\0') || cpy[i] == '\0')
	{
		free(cpy);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(cpy) - i + 1));
	if (!str)
	{
		free (cpy);
		return (NULL);
	}
	i++;
	j = 0;
	while (cpy[i])
		str[j++] = cpy[i++];
	str[j] = '\0';
	free (cpy);
	return (str);
}

static int	is_a_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	else
		return (0);
}

static char	*read_file(int fd, char *cpy)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		nbytes;

	nbytes = 1;
	while (is_a_line(cpy) == 0 && nbytes > 0)
	{
		nbytes = read (fd, buffer, BUFFER_SIZE);
		if (nbytes > 0)
		{
			buffer[nbytes] = '\0';
			tmp = ft_strjoin(cpy, buffer);
			cpy = tmp;
		}
	}
	if (nbytes == -1)
	{
		free(cpy)
		return (NULL);
	}
	return (cpy);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cpy[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cpy[fd] = read_file(fd, cpy[fd]);
	if (!cpy[fd])
		return (NULL);
	line = get_one_line(cpy[fd]);
	if (!line)
	{
		if (cpy[fd])
			free (cpy[fd]);
		return (NULL);
	}
	cpy[fd] = save_cpy(cpy[fd]);
	return (line);
}
