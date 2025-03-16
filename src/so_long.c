/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:13:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 12:13:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_ber(t_data *data)
{
	int i;

	i = ft_strlen(data->ber);
	if (data->ber[i - 1] != 'r' || data->ber[i - 2] != 'e' ||
		data->ber[i - 3] != 'b' || data->ber[i - 4] != '.')
		ft_error(data, "The map format is .ber");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("¡ERROR! The program needs two arguments");
		return (1);
	}
	data.ber = argv[1];
	check_ber(&data);
	ft_load_map(&data);
	ft_init(&data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, on_destroy, &data);
	mlx_hook(data.win, 2, 1L >> 0, key_press, &data);
	mlx_loop(data.mlx);
	return (0);
}
