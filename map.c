/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:56:06 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/30 02:05:43 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./getnextline/get_next_line.h"
#include "./ft_printf/ft_printf.h"
#include <stdlib.h> 
#include "getnextline/get_next_line.h"
#include "so_long.h"

char	*merge(char *newline, char *oldline)
{
	char	*arr;
	int		i;
	int		j;

	i = -1;
	j = 0;
	arr = malloc(ft_strlen(newline) + ft_strlen(oldline) + 1);
	if (!arr)
		return (NULL);
	while (oldline[++i])
		arr[i] = oldline[i];
	while (newline[j])
		arr[i++] = newline[j++];
	arr[i] = 0;
	return (arr);
}

char	*read_line(char *file_name)
{
	int		file;
	int		i;
	char	*line;
	char	*oldlines;
	char	*tmp;

	file = open(file_name, O_RDONLY);
	if (file < 0)
		to_exit();
	i = 1;
	line = "";
	oldlines = ft_strdup("");
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break ;
		tmp = merge(line, oldlines);
		free(oldlines);
		oldlines = tmp;
		free(line);
	}
	close(file);
	return (oldlines);
}

int	find_row(char *map)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		if (map[i] == '\n')
			count++;
	}
	return (count);
}

int	find_row_2d(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != 0)
	{
		while (map[i][j] != '\0' && map[i][j] != 0 && map[i][j] != '\n')
			j++;
		j = 0;
		i++;
	}
	return (i);
}

char	*in_line_values(int len, char *map)
{
	int			i;
	static int	k = 0;
	char		*arr;

	i = 0;
	arr = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		arr[i] = map[k];
		i++;
		k++;
	}
	arr[i] = '\0';
	k++;
	return (arr);
}
