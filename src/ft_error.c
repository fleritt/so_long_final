/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:27:39 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 20:27:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

int	on_destroy(t_data *data)
{
	if (data->map)
		destroy_map(data);
	mlx_destroy_image(data->mlx, data->images->player);
	mlx_destroy_image(data->mlx, data->images->empty);
	mlx_destroy_image(data->mlx, data->images->wall);
	mlx_destroy_image(data->mlx, data->images->exit);
	mlx_destroy_image(data->mlx, data->images->collectible);
	free(data->images);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	ft_error(char *error, t_data *data)
{
	ft_printf(error);
	on_destroy(data);
}

void	ft_invalid_map(char *line, int fd)
{
	free(line);
	ft_printf("¡ERROR! The map is not valid");
	close(fd);
	exit(EXIT_FAILURE);
}
void	ft_player_invalid(char *error, t_data *data)
{
	ft_printf(error);
	destroy_map(data);
	exit(EXIT_FAILURE);
}
