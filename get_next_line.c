/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:22:55 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/08 18:38:04 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	printf("valeur de la ligne =%s \n", s2);

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
	if (!cpy[i])
	{
		if (cpy)
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
	{
		str[j] = cpy[i];
		i++;
		j++;
	}
	str[j] = '\0';
	if (cpy)
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
	char	*buffer;
	char	*tmp;
	int		nbytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbytes = 1;
	buffer[0] = '\0';
	while (is_a_line(cpy) == 0 && nbytes > 0)
	{
		nbytes = read (fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		if (cpy == NULL)
			cpy = ft_strdup(buffer);
		else if (buffer[0] != '\0')
		{
			tmp = ft_strjoin(cpy, buffer);
			free (cpy);
			cpy = tmp;
		}
	}
	if (cpy != buffer)	
		free (buffer);
	return (cpy);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cpy = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cpy = read_file(fd, cpy);
	if (!cpy)
		return (NULL);
	line = get_one_line(cpy);
	if (!line)
	{
		if (cpy )
			free (cpy);
			printf("pointeur sur cpy si pas de ligne = %p\n", cpy);
		return (NULL);
	}
	printf("pointeur sur cpy si ligne = %p\n", cpy);
	cpy = save_cpy(cpy);
	return (line);
}
