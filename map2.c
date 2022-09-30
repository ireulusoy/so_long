/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:33:34 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/29 23:31:58 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./getnextline/get_next_line.h"
#include "./ft_printf/ft_printf.h"
#include <stdlib.h> 
#include "getnextline/get_next_line.h"
#include "so_long.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = 0;
	if (size != 0)
	{
		while (src[c] != '\0' && c < (size - 1))
		{
			dest[c] = src[c];
			c++;
		}
		dest[c] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	single_char(char **map, int i, int j, char same)
{
	static int	e = 0;
	static int	c = 0;
	static int	p = 0;

	if (same == 'E')
	{
		if (map[i][j] == same)
			e++;
		return (e);
	}
	if (same == 'C')
	{
		if (map[i][j] == same)
			c++;
		return (c);
	}
	if (same == 'P')
	{
		if (map[i][j] == same)
			p++;
		return (p);
	}
	return (0);
}

int	check_content(int e, int c, int p)
{
	if (e >= 2 || p >= 2)
	{
		ft_printf ("Error\nno more than an exit nor starting point!\n");
		to_exit();
	}
	if (e < 1 || c < 1 || p < 1)
	{
		ft_printf("Error\nlack of chars\n");
		to_exit();
	}
	return (1);
}

int	traverse2(char **map)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	while (map[i] != 0)
	{
		while (map[i][j] != '\0' || map[i][j] != 0)
		{
			if (map[i][j] != '0' && map[i][j] != '1' &&
				map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
			{
				ft_printf("Error\nother char!!");
				exit(1);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	traverse(char **map)
{
	unsigned int	j;
	unsigned int	i;
	int				e;
	int				c;
	int				p;

	i = 0;
	j = 0;
	e = 0;
	c = 0;
	p = 0;
	while (map[i] != 0)
	{
		while (map[i][j] != '\0' || map[i][j] != 0)
		{
			e = single_char(map, i, j, 'E');
			c = single_char(map, i, j, 'C');
			p = single_char(map, i, j, 'P');
			j++;
		}
		j = 0;
		i++;
	}	
	check_content(e, c, p);
	return (1);
}
