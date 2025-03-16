/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:28:31 by rfleritt          #+#    #+#             */
/*   Updated: 2025/03/08 14:11:23 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void on_destroy(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(EXIT_FAILURE);
    return (0);
}
void ft_error(t_data *data, char *str)
{
    ft_printf(str);
    on_destroy(data);
}