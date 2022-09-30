/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:29:03 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/30 00:24:38 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "getnextline/get_next_line.h"

int	*get_size(char **map)
{
	int		row;
	int		i;	
	int		j;
	int		*temp;

	i = 0;
	j = 0;
	row = find_row_2d(map);
	while (map[i][j] != '\0')
		j++;
	temp = malloc(sizeof(int) * 2);
	*temp = row;
	*(temp + 1) = j;
	return (temp);
}

int	get_position(t_var *var, char **map)
{
	int	i;
	int	j;

	var->pos.i = 0;
	var->pos.j = 0;
	i = 0;
	j = 0;
	while (map[i] != 0)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				var->pos.i = i;
				var->pos.j = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	count_collectible(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i] != 0)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}

void	print_noimage(void)
{
	ft_printf("no image");
	exit(1);
}

void	assign_img(t_var *var, void *mlx)
{
	int		img_width;
	int		img_height;

	var->player_img = mlx_xpm_file_to_image
		(mlx, var->player_path, &img_width, &img_height);
	if (var->player_img == NULL)
		print_noimage();
	var->collectible_img = mlx_xpm_file_to_image
		(mlx, var->collectible_path, &img_width, &img_height);
	if (var->collectible_img == NULL)
		print_noimage();
	var->exit_img = mlx_xpm_file_to_image
		(mlx, var->exit_path, &img_width, &img_height);
	if (var->exit_img == NULL)
		print_noimage();
	var->wall_img = mlx_xpm_file_to_image
		(mlx, var->wall_path, &img_width, &img_height);
	if (var->wall_img == NULL)
		print_noimage();
}
