/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:11:18 by marvin            #+#    #+#             */
/*   Updated: 2025/01/11 10:11:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, int x, int y, t_data *data)
{
    if (x < 0 || y < 0 || x >= data->width || y >= data->height)
        return;
    if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'E')
        return;
    if (map[y][x] == 'C')
        data->s--;
    map[y][x] = 'F';
    ft_flood_fill(map, x + 1, y, data);
    ft_flood_fill(map, x - 1, y, data);
    ft_flood_fill(map, x, y + 1, data);
    ft_flood_fill(map, x, y - 1, data);
}

void	ft_check_path(t_data *data)
{
    char	**map_copy;
    int		y;

    map_copy = (char **)malloc(sizeof(char *) * (data->height + 1));
    if (!map_copy)
        ft_error("ERROR!! Memory allocation failed", data);
    y = 0;
    while (y < data->height)
    {
        map_copy[y] = ft_strdup(data->map[y]);
        if (!map_copy[y])
            ft_error("ERROR!! Memory allocation failed", data);
        y++;
    }
	data->s = data->c;
    ft_flood_fill(map_copy, data->x, data->y, data);
    y = 0;
    while (y < data->height)
        free(map_copy[y++]);
    free(map_copy);
    if (data->s > 0)
        ft_error("ERROR!! The player cannot reach all collectibles or the exit", data);
}
void ft_check_map(t_data *data)
{
    int x;
    int y;

    y = data->height;
	x = 0;
	while(x < data->width)
	{
		if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != '\n' 
			&& data->map[y - 1][x] != '\0')
			ft_player_invalid("The map is not valid", data);
		x++;
	}
}
void ft_count_p(t_data *data)
{
	int x;
	int y;

	y = 0;
	while(y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			if (data->map[y][x] == 'P')
				data->player++;
			if (data->map[y][x] == 'E')
				data->exit++;
			x++;
		}
		y++;
	}
}
void	ft_check_player(t_data *data)
{
	if (data->player != 1)
		ft_error("ERROR!! only one character", data);
	if (data->exit != 1)
		ft_error("ERROR!! only one exit", data);
	if (data->c < 1)
		ft_error("ERROR!! At least one collectible is needed", data);
}
