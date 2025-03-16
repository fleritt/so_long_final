/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:13:30 by rfleritt          #+#    #+#             */
/*   Updated: 2025/03/08 15:46:33 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_valid_fl(t_data *data, char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] != '1')
			ft_error(data, "The map has to be surrounded by walls");
		i++;
	}
}

void    ft_valid_char(t_data *data)
{
    
}

void    ft_valid_map(t_data *data)
{
    int     fd;
    int     i;
    char    *line;
    
    fd = open(data->ber, O_RDONLY);
    line = get_next_line(fd, 0);
    ft_valid_fl(data, line);
    while() 
    {
        
    }
}

void    ft_load_map(t_data *data)
{
    int     fd;
    char    *line;
    int     i;
    
    ft_valid_map(data);
}