/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:30:49 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/30 02:10:54 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "getnextline/get_next_line.h"

void	assign_path(t_var *var)
{
	var->player_path = "./images/player.xpm";
	var->exit_path = "./images/exit.xpm";
	var->wall_path = "./images/wall.xpm";
	var->collectible_path = "./images/pc.xpm";
}

void	if_condition(t_var *var, int *i, int *j)
{
	while (var->map[*i][*j] != '\0')
	{
		if (var->map[*i][*j] == 'P')
			mlx_put_image_to_window
		(var->mlx, var->win, var->player_img, *j * 64, *i * 64);
		if (var->map[*i][*j] == 'C')
			mlx_put_image_to_window
				(var->mlx, var->win, var->collectible_img, *j * 64, *i * 64);
		if (var->map[*i][*j] == '1')
			mlx_put_image_to_window
				(var->mlx, var->win, var->wall_img, *j * 64, *i * 64);
		if (var->map[*i][*j] == 'E')
			mlx_put_image_to_window
				(var->mlx, var->win, var->exit_img, *j * 64, *i * 64);
		(*j)++;
	}
		(*i)++;
		*j = 0;
}

char	**print_the_map(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(var->mlx, var->win);
	while (var->map[i] != 0)
		if_condition(var, &i, &j);
	return (0);
}

int	to_exit(void)
{
	ft_printf("Error\nAn error occurred \n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_var	var;
	int		*getsize;

	if (argc != 2)
	{
		ft_printf("Error\nno more than 2 arg");
		return (0);
	}
	check_the_ber(argv[1]);
	var = (t_var){0};
	var.mlx = mlx_init();
	assign_path(&var);
	assign_img (&var, var.mlx);
	var.map = get_the_map(argv[1]);
	getsize = get_size(var.map);
	var.win = mlx_new_window
		(var.mlx, *(getsize + 1) * 64, *getsize * 64, "New Window!");
	print_the_map(&var);
	get_position(&var, var.map);
	check_the_map(var.map);
	clone(&var);
	mlx_hook(var.win, 2, 0, &on_key_down, &var);
	mlx_hook(var.win, 17, 0, &to_exit, &var);
	mlx_loop(var.mlx);
}
