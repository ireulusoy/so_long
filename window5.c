/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:52:36 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/29 21:02:09 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**clone_the_map(t_var *var, char **clone_map, int row, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < len)
		{
			clone_map[i][j] = var->map[i][j];
			++j;
		}
		clone_map[i][j] = '\0';
		++i;
	}
	clone_map[i] = NULL;
	return (clone_map);
}

char	**clone(t_var *var)
{
	char	**clone_map;
	int		i;
	int		j;
	int		len;
	int		row;

	i = 0;
	j = 0;
	row = 0;
	while (var->map[row])
		row++;
	len = 0;
	while (var->map[0][len])
		len++;
	clone_map = malloc(sizeof(char *) * (row + 1));
	i = -1;
	while (++i < row)
		clone_map[i] = malloc(sizeof(char) * (len + 1));
	clone_the_map(var, clone_map, row, len);
	find_rec(var, clone_map);
	i = 0;
	while (clone_map[i])
		free(clone_map[i++]);
	free(clone_map);
	return (clone_map);
}
