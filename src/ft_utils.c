/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:54:42 by rfleritt          #+#    #+#             */
/*   Updated: 2025/04/01 14:34:44 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_2()
{
	ft_printf("¡ERROR!");
	exit(EXIT_FAILURE);
}

int	    ft_check_rectangular(t_data *data)
{
    int	y;
    int	row_length;

    y = 0;
    row_length = ft_strlen(data->map[0]);
    while (y < data->height)
    {
        if ((int)ft_strlen(data->map[y]) != row_length)
            return (1);
        y++;
    }
    return (0);
}
