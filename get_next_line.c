/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:22:55 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/06 15:29:55 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_one_line(char *str)
{
	int		i;
	char	*s2;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	s2 = malloc(sizeof(char) * (i + 2));
	if (!s2)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s2[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s2[i] = '\n';
	s2[i++] = '\0';
	return (s2);
}



char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*cpy;



}
