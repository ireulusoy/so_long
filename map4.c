/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:18:46 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/30 01:33:18 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./getnextline/get_next_line.h"
#include "./ft_printf/ft_printf.h"
#include <stdlib.h> 
#include "getnextline/get_next_line.h"
#include "so_long.h"

int	is_it_rectangle(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (map[i][k] != 0)
		k++;
	i++;
	while (map[i] != 0)
	{
		while (map[i][j] != '\0')
			j++;
		if (j != k)
		{
			ft_printf("Error\nevery line must be in the same size");
			exit(1);
			return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

int	last_row(char **map)
{
	int	j;
	int	last_row;

	j = 0;
	last_row = find_row_2d(map);
	while (map[last_row - 1][j] != '\0' && map[last_row - 1][j] != '\n')
	{
		if (map[last_row - 1][j] == '1')
			j++;
		else
		{
			ft_printf("Error\nlast row is not surrounded by the walls\n");
			exit(1);
			return (0);
		}
	}
	return (1);
}

int	check_the_ber(char *str)
{
	int		i;
	int		k;
	char	*ber;

	i = 0;
	k = 0;
	ber = ".ber";
	while (str[i])
		i++;
	if (i < 5)
	{
		ft_printf("Error\nno valid name\n");
		exit(1);
	}
	i -= 4;
	while (str[i])
	{
		if (ber[k++] != str[i++])
		{
			ft_printf("Error\nnot ending with .ber\n");
			exit(1);
		}
	}
	return (1);
}
