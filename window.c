/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:52:59 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/30 00:24:28 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "getnextline/get_next_line.h"

void	go_up(int c, t_var *var)
{
	if (!(var->map[var->pos.i - 1][var->pos.j] == '1'
		|| (var->map[var->pos.i - 1][var->pos.j] == 'E' && (c != 0))))
	{
		ft_printf("%d\n", ++var->step);
		if (var->map[var->pos.i - 1][var->pos.j] == 'E')
			exit(1);
			var->pos.i--;
		if (var->map[var->pos.i][var->pos.j] == 'C')
			c--;
			var->map[var->pos.i][var->pos.j] = 'P';
			var->map[var->pos.i + 1][var->pos.j] = '0';
	}
}

void	go_down(int c, t_var *var)
{
	if (!(var->map[var->pos.i + 1][var->pos.j] == '1'
		|| (var->map[var->pos.i + 1][var->pos.j] == 'E' && (c != 0))))
	{
		ft_printf("%d\n", ++var->step);
		if (var->map[var->pos.i + 1][var->pos.j] == 'E')
			exit(1);
		var->pos.i++;
		if (var->map[var->pos.i][var->pos.j] == 'C')
			c--;
		var->map[var->pos.i][var->pos.j] = 'P';
		var->map[var->pos.i - 1][var->pos.j] = '0';
	}
}

void	go_right(int c, t_var *var)
{
	if (!(var->map[var->pos.i][var->pos.j + 1] == '1'
		|| (var->map[var->pos.i][var->pos.j + 1] == 'E' && (c != 0))))
	{
		ft_printf("%d\n", ++var->step);
		if (var->map[var->pos.i][var->pos.j + 1] == 'E')
			exit(1);
		var->pos.j++;
		if (var->map[var->pos.i][var->pos.j] == 'C')
			c--;
		var->map[var->pos.i][var->pos.j] = 'P';
		var->map[var->pos.i][var->pos.j - 1] = '0';
	}
}

void	go_left(int c, t_var *var)
{
	if (!(var->map[var->pos.i][var->pos.j - 1] == '1'
		|| (var->map[var->pos.i][var->pos.j - 1] == 'E' && (c != 0))))
	{
		ft_printf("%d\n", ++var->step);
		if (var->map[var->pos.i][var->pos.j - 1] == 'E')
			exit(1);
		var->pos.j--;
		if (var->map[var->pos.i][var->pos.j] == 'C')
			c--;
		var->map[var->pos.i][var->pos.j] = 'P';
		var->map[var->pos.i][var->pos.j + 1] = '0';
	}
}

int	on_key_down(int keycode, t_var *var)
{
	int	c;

	c = count_collectible(var->map);
	if (keycode == ESC)
		to_exit();
	if (keycode == UP)
		go_up(c, var);
	if (keycode == LEFT)
		go_left(c, var);
	if (keycode == DOWN)
		go_down(c, var);
	if (keycode == RIGHT)
		go_right(c, var);
	if (keycode == 27)
		exit(1);
	print_the_map(var);
	return (0);
}
