/* ************************************************************************** */
/*                                                                            */
/*           <                                     :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:14:51 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 12:14:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32
# define WIDTH 600
# define HEIGHT 400

# define PLAYER "./tools/sprites/player.xpm"
# define EXIT "./tools/sprites/exit.xpm"
# define WALL "./tools/sprites/wall.xpm"
# define EMPTY "./tools/sprites/empty.xpm"
# define COLLECTIBLE "./tools/sprites/collectible.xpm"

# define GREEN	"\033[0;32m"
# define RESET 	"\033[0m"

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

typedef struct s_image
{
	void	*player;
	void	*wall;
	void	*empty;
	void	*collectible;
	void	*exit;
} t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int 	fd;
	int		height;
	int		width;
	int		x;
	int		y;
	int		i;
	int		step;
	int		c;
	int		player;
	int		exit;
	int		e;
	int		s;
	char	**map;
	char	*ber;
	t_image	*images;
} t_data;

int		on_destroy(t_data *data);
int		key_press(int key, t_data *data);
void	ft_load_map(t_data *data);
void	ft_error(char *error, t_data *data);
void	ft_draw_map(t_data *data);
void	ft_invalid_map(char *line, int fd);
void	ft_victory(t_data *data);
void	destroy_map(t_data *data);
void	ft_count_coll(t_data *data);
void	ft_check_map(t_data *data);
void	ft_count_p(t_data *data);
void	ft_check_player(t_data *data);
void	ft_player_invalid(char *error, t_data *data);
void	ft_error_2();
void	ft_check_path(t_data *data);
void	ft_flood_fill(char **map, int x, int y, t_data *data);
void	ft_find_player(t_data *data);
int		ft_check_rectangular(t_data *data);

#endif
