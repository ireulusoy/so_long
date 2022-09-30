/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irulusoy <irulusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:13:01 by irulusoy          #+#    #+#             */
/*   Updated: 2022/09/29 23:24:53 by irulusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>//malloc
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>//open
# include "ft_printf/ft_printf.h"
# include "./mlx/mlx.h"
# include "getnextline/get_next_line.h"
# include <string.h>
# include <stddef.h>
# include <sys/errno.h>

typedef struct s_var_position
{
	int	i;
	int	j;

}t_var_position;

typedef struct s_var
{
	void			*mlx;
	void			*player_img;
	void			*collectible_img;
	void			*exit_img;
	void			*wall_img;
	char			*player_path;
	char			*collectible_path;
	char			*exit_path;
	char			*wall_path;
	int				img_width;
	int				img_height;
	void			*win;
	char			**map;
	int				step;
	t_var_position	pos;
	t_var_position	posc;
}t_var;

char			*merge(char *newline, char *oldline);
char			*read_line(char *file_name);
int				find_row(char *map);
int				find_row_2d(char **map);
char			*in_line_values(int len, char *map);
int				single_char(char **map, int i, int j, char same);
int				check_content(int e, int c, int p);
int				traverse(char **map);
int				traverse2(char **map);
int				is_it_rectangle(char **map);
int				last_row(char **map);
int				first_row(char **map);
int				first_column(char **map);
int				last_column(char **map);
int				if_enclosed_by_walls(char **map);
char			**get_the_map(char *str);
void			go_up(int c, t_var *var);
void			go_down(int c, t_var *var);
void			go_right(int c, t_var *var);
void			go_left(int c, t_var *var);
int				on_key_down(int keycode, t_var *var);
int				*get_size(char **map);
int				get_position(t_var *var, char **map);
int				count_collectible(char **map);
void			print_noimage(void);
void			assign_img(t_var *var, void *mlx);
void			assign_path(t_var *var);
char			**print_the_map(t_var *var);
void			if_condition(t_var *var, int *i, int *j);
int				to_exit(void);
int				check_the_map(char **map);
void			zero(char **clone_map, int i, int j);
void			lets_exit(void);
int				check_zero(char **clone_map);
int				**find_rec(t_var *var, char **clone_map);
char			**clone(t_var *var);
char			**clone_the_map(t_var *var, char **clone_map, int row, int len);
int				check_the_ber(char *str);
char			**ft_split(char const *s, char c);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);

# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	53

#endif
