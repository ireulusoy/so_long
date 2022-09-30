/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:38:05 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/30 01:34:06 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_the_map(char **map)
{
	traverse(map);
	if_enclosed_by_walls(map);
	is_it_rectangle(map);
	traverse2(map);
	return (0);
}

void	zero(char **clone_map, int i, int j)
{
	clone_map[i][j] = 's';
	if (clone_map[i + 1][j] != 's' && clone_map[i + 1][j] != '1'
		&& clone_map[i + 1][j] != 'E')
		zero(clone_map, i + 1, j);
	if (clone_map[i][j - 1] != 's' && clone_map[i][j - 1] != '1'
		&& clone_map[i][j - 1] != 'E')
		zero(clone_map, i, j - 1);
	if (clone_map[i - 1][j] != 's' && clone_map[i - 1][j] != '1'
		&& clone_map[i - 1][j] != 'E')
		zero(clone_map, i - 1, j);
	if (clone_map[i][j + 1] != 's' && clone_map[i][j + 1] != '1'
		&& clone_map[i][j + 1] != 'E')
		zero(clone_map, i, j + 1);
}

void	lets_exit(void)
{
	ft_printf("\nError:\n no valid path");
	exit (1);
}

int	check_zero(char **clone_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (clone_map[i] != 0)
	{
		while (clone_map[i][j] != '\0')
		{
			if (clone_map[i][j] == 'C')
				return (0);
			else if (clone_map[i][j] == 'E')
			{
				if (clone_map[i + 1][j] != 's' && clone_map[i - 1][j] != 's'
					&& clone_map[i][j + 1] != 's' && clone_map[i][j - 1] != 's')
					return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	**find_rec(t_var *var, char **clone_map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (var->map[i] != 0)
	{
		while (var->map[i][j] != '\0')
		{
			if (clone_map[i][j] == 'P')
			{
				zero(clone_map, i, j);
				k = -1;
				while (clone_map[++k])
					if (!check_zero(clone_map))
						lets_exit();
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
