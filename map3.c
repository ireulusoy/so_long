/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:34:24 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/30 00:50:36 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./getnextline/get_next_line.h"
#include "./ft_printf/ft_printf.h"
#include <stdlib.h> 
#include "getnextline/get_next_line.h"
#include "so_long.h"

int	first_row(char **map)
{
	int	j;

	j = 0;
	while (map[0][j] != '\0' && map[0][j] != '\n')
	{
		if (map[0][j] == '1')
			j++;
		else
		{
			ft_printf("Error\nfirst row is not surrounded by the walls");
			exit(1);
			return (0);
		}
	}
	return (1);
}

int	first_column(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
	{
		if (map[i][0] == '1')
			i++;
		else
		{
			ft_printf("Error\nfirst columns are not surrounded by the walls");
			exit(1);
			return (0);
		}
	}
	return (1);
}

int	last_column(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != 0)
	{
		while (map[i][j] != '\0' && map[i][j] != '\n')
			j++;
		--j;
		if (map[i][j] == '1')
			i++;
		else
		{
			ft_printf("Error\nlast column is not surrounded by the walls");
			exit(1);
			return (0);
		}
	}
	return (1);
}

int	if_enclosed_by_walls(char **map)
{
	first_row(map);
	last_row(map);
	first_column(map);
	last_column(map);
	return (1);
}

char	**get_the_map(char *str)
{
	char	*my_map;
	char	**finally_in_2d;
	int		i;

	i = 0;
	my_map = read_line(str);
	while (my_map[i])
	{
		if (my_map[i + 1] && my_map[i] == '\n' && my_map[i + 1] == '\n')
			exit(1);
		i++;
	}
	finally_in_2d = ft_split(my_map, '\n');
	free(my_map);
	return (finally_in_2d);
}
