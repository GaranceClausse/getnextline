/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:22:55 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/07 12:21:09 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_one_line(char *cpy)
{
	int		i;
	char	*s2;

	i = 0;
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
		s2[i] = '\n';
	s2[i++] = '\0';
	return (s2);
}

static int	is_a_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	else
		return (0);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
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

static char	*read_file(int fd, char *cpy)
{
	char		*buffer;
	size_t		nbytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbytes = (sizeof(char) * (BUFFER_SIZE + 1));
	while (read(fd, buffer, nbytes) != 0)
	{
		cpy = read(fd, buffer, nbytes);
		if (is_a_line(cpy) == 1)
			return (get_one_line(cpy));
		else
			cpy = ft_strjoin(cpy, read_file(fd, cpy));
	}


}


char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*cpy;



}
